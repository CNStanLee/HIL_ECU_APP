#include "can_drv.h"
#include "sleep.h"
#include "mb_interface.h"

#define DEBUG_MODE 0

#if DEBUG_MODE
#define debug_printf(fmt, ...) printf(stderr, fmt, __VA_ARGS__)
#else
#define debug_printf(fmt, ...) do {} while (0)
#endif


uint8_t       RX_buffer[FrameNum];
uint8_t       TX_buffer[FrameNum];

void ten_nsleep(uint32_t num_cycles) {
    uint32_t delay_ns = num_cycles;
    for (volatile uint32_t i = 0; i < delay_ns; ++i) {
    }
}

void m_usleep(uint32_t num_cycles) {
    uint32_t delay_ns = num_cycles * 100;
    for (volatile uint32_t i = 0; i < delay_ns; ++i) {
    }
}

void can_init(uint32_t can_addr){
    uint8_t Status;
    /* reset all pins */
    can_set_pin(can_addr, RST, FALSE);
    can_set_pin(can_addr, ALE, FALSE);
    can_set_pin(can_addr, RD, FALSE);
    can_set_pin(can_addr, WR, FALSE);
    can_set_pin(can_addr, CS, FALSE);

    /* set choose chip */
    //can_set_pin(can_addr, CS, TRUE);

    /* set reset chip */
    can_set_pin(can_addr, RST, TRUE);
    m_usleep(200);    // wait reset
    can_set_pin(can_addr, RST, FALSE);

    /* reset finish */
    debug_printf("can bus reset finished\r\n");

    /* enter reset mode*/
    do
    {
        write_register(can_addr, SJA_MOD, RM_BIT);
		Status = read_register(can_addr, SJA_MOD) ;
    }
    while(!(Status & RM_BIT));
    debug_printf("enter reset mode\r\n");

    // basic mode set
    //    write_register(can_addr, SJA_BTR0, 0x43);
    //    write_register(can_addr, SJA_BTR1, 0x2f); //16MHZ

	/*new config*/
	// BTR0  0X40 BTR1 0X1C
	write_register(can_addr, SJA_BTR0, 0x40);
	write_register(can_addr, SJA_BTR1, 0x1c);
    write_register(can_addr, SJA_CDR, CANMode_BIT|CLKOff_BIT);//Peli CAN, output clock off
    // PeliCAN mode parameters set
    write_register(can_addr, SJA_IER, RIE_BIT); // enable receive irq
    write_register(can_addr, SJA_CMR, RRB_BIT); // release rxd buffer
    debug_printf("enter Pelican mode\r\n");
    // init iden code
    write_register(can_addr, SJA_ACR0, 0x00);
    write_register(can_addr, SJA_ACR1, 0x00);
    write_register(can_addr, SJA_ACR2, 0x00);
    write_register(can_addr, SJA_ACR3, 0x00);
    // init mask
    write_register(can_addr, SJA_AMR0, 0xff);
    write_register(can_addr, SJA_AMR1, 0xff);
    write_register(can_addr, SJA_AMR2, 0xff);
    write_register(can_addr, SJA_AMR3, 0xff);
    debug_printf("code and mask set\r\n");
    // enter normal mode
    Status = read_register(can_addr, SJA_MOD);
    do{
        write_register(can_addr, SJA_MOD, 0x00);
        Status = read_register(can_addr, SJA_MOD);
    }while(!(Status == 0x00));
    debug_printf("enter normal mode\r\n");
    usleep(1000);
    debug_printf("can controller init done\r\n");
}
void can_set_pin(uint32_t can_addr, uint8_t pin, uint8_t value){
	struct can_regs * regs = (struct can_regs *)can_addr;
	write_gpio_1(&regs->control, 0, pin, value);
}
void can_set_data(uint32_t can_addr, uint8_t value){
	struct can_regs * regs = (struct can_regs *)can_addr;
	write_gpio_8(&regs->tx_fifo, 0, value);
}
uint8_t can_read_data(uint32_t can_addr){
	uint8_t ret = 0x00;
	struct can_regs * regs = (struct can_regs *)can_addr;
	ret = read_gpio_8(&regs->rx_fifo, 0);
	return ret;
}
void write_register(uint32_t can_addr, uint8_t reg_addr, uint8_t reg_data){
    /* set choose chip */
    can_set_pin(can_addr, CS, TRUE);

    /* set ALE, prepare to set addr */
    can_set_pin(can_addr, ALE, TRUE);
    /* transfer addr value*/
    can_set_data(can_addr, reg_addr);
    /* clear ALE */
    can_set_pin(can_addr, ALE, FALSE);
    /* wait 90ns */
    ten_nsleep(9);
    //usleep(1);
    /* set reg data*/
    can_set_data(can_addr, reg_data);
    /* prepare to trans data*/
    can_set_pin(can_addr, WR, TRUE);
    /* wait write */
    ten_nsleep(16);
    //usleep(1);
    /* release chip*/

    can_set_pin(can_addr, WR, FALSE);
    can_set_pin(can_addr, CS, FALSE);
}
uint8_t read_register(uint32_t can_addr, uint8_t reg_addr){
    uint8_t reg_data;

    /* set choose chip*/
    can_set_pin(can_addr, CS, TRUE);

    /* set ALE, prepare to set addr */
    can_set_pin(can_addr, ALE, TRUE);
    /* transfer addr value*/
    can_set_data(can_addr, reg_addr);
    /* clear ALE */
    can_set_pin(can_addr, ALE, FALSE);
    /* wait 90ns */
    //ten_nsleep(9);
    usleep(1);
    /* prepare to read data*/
    can_set_pin(can_addr, RD, TRUE);
    /* wait read */
    //ten_nsleep(15);
    usleep(1);
    /* read data */
    reg_data = can_read_data(can_addr);
    /* clear RD*/
    can_set_pin(can_addr, RD, FALSE);
    /* clear CS*/
    can_set_pin(can_addr, CS, FALSE);

    return reg_data;
}

void can_txd(uint32_t can_addr){
    uint8_t Status;

    // init head
        TX_buffer[0] = 0x88;//.7=1 extend；.6=0 data; .3~0=8 data length
        TX_buffer[1] = 0x12;//this node addr
        TX_buffer[2] = 0x23;//
        TX_buffer[3] = 0x56;//
        TX_buffer[4] = 0xff;//
    // init data
        TX_buffer[5]  = 0x11;
        TX_buffer[6]  = 0x22;
        TX_buffer[7]  = 0x33;
        TX_buffer[8]  = 0x44;//
        TX_buffer[9]  = 0x55;//
        TX_buffer[10] = 0x66;//
        TX_buffer[11] = 0x77;//
        TX_buffer[12] = 0x88;//
        debug_printf("init buffer done\r\n");
    do{
        Status = read_register(can_addr, SJA_SR);
    }while(Status & RS_BIT); // SR.4 = 1 receiving , wait
    debug_printf("SR4 OK\r\n");
    do{
        Status = read_register(can_addr, SJA_SR);
    }while(!(Status & TCS_BIT)); // SR.3 = 0 transfering , wait
    debug_printf("SR3 OK\r\n");
    do{
        Status = read_register(can_addr, SJA_SR);
    }while(!(Status & TBS_BIT)); //SR.2 = 0, transfer reg is locked, wait
    debug_printf("SR2 OK\r\n");
    // transfer data to buffer
    write_register(can_addr, SJA_TBSR2, TX_buffer[2]);
    write_register(can_addr, SJA_TBSR3, TX_buffer[3]);
    write_register(can_addr, SJA_TBSR4, TX_buffer[4]);
    write_register(can_addr, SJA_TBSR5, TX_buffer[5]);
    write_register(can_addr, SJA_TBSR1, TX_buffer[1]);
    write_register(can_addr, SJA_TBSR0, TX_buffer[0]);
    write_register(can_addr, SJA_TBSR6, TX_buffer[6]);
    write_register(can_addr, SJA_TBSR7, TX_buffer[7]);
    write_register(can_addr, SJA_TBSR8, TX_buffer[8]);
    write_register(can_addr, SJA_TBSR9, TX_buffer[9]);
    write_register(can_addr, SJA_TBSR10, TX_buffer[10]);
    write_register(can_addr, SJA_TBSR11, TX_buffer[11]);
    write_register(can_addr, SJA_TBSR12, TX_buffer[12]);

    //request to transer
    write_register(can_addr, SJA_CMR, TR_BIT | AT_BIT);
    //write_register(can_addr, SJA_CMR, 0x01);
    microblaze_disable_interrupts();
    debug_printf("tx done\r\n");
    microblaze_enable_interrupts();
}
void can_rxd(uint32_t can_addr){
    uint8_t Status;
    uint8_t Rxd_data;

    Status = read_register(can_addr, SJA_IR);

    if(Status & RI_BIT){
        debug_printf("DETECTED RXD MSG\r\n");
        RX_buffer[0] =   read_register(can_addr, SJA_RBSR0);
        RX_buffer[1] =   read_register(can_addr, SJA_RBSR1);
        RX_buffer[2] =   read_register(can_addr, SJA_RBSR2);
        RX_buffer[3] =   read_register(can_addr, SJA_RBSR3);
        RX_buffer[4] =   read_register(can_addr, SJA_RBSR4);

        RX_buffer[5] =   read_register(can_addr, SJA_RBSR5);
        RX_buffer[6] =   read_register(can_addr, SJA_RBSR6);
        RX_buffer[7] =   read_register(can_addr, SJA_RBSR7);
        RX_buffer[8] =   read_register(can_addr, SJA_RBSR8);
        RX_buffer[9] =   read_register(can_addr, SJA_RBSR9);
        RX_buffer[10] =  read_register(can_addr, SJA_RBSR10);
        RX_buffer[11] =  read_register(can_addr, SJA_RBSR11);
        RX_buffer[12] =  read_register(can_addr, SJA_RBSR12);

        write_register(can_addr, SJA_CMR, RRB_BIT); // release receive register
        Status = read_register(can_addr, SJA_ALC); // release judge catch
        Status = read_register(can_addr, SJA_ECC); // release error catch
    }

    write_register(can_addr, SJA_IER, RIE_BIT);// enable rx irq


    Rxd_data = RX_buffer[7];
    debug_printf("rx done\r\n");
    debug_printf("rxd data = %d\r\n", Rxd_data);
}

void can_txd_frame(struct can_data_frame *frame){
    uint8_t Status;
    uint32_t can_addr;
    can_addr = frame->can_addr;
    // init head
        TX_buffer[0] = frame->data_mode;//.7=1 extend；.6=0 data; .3~0=8 data length
        TX_buffer[1] = frame->addr1;//this node addr
        TX_buffer[2] = frame->addr2;//
        TX_buffer[3] = frame->addr3;//
        TX_buffer[4] = frame->config_code;//
    // init data
        TX_buffer[5]  = frame->data0;
        TX_buffer[6]  = frame->data1;
        TX_buffer[7]  = frame->data2;
        TX_buffer[8]  = frame->data3;//
        TX_buffer[9]  = frame->data4;//
        TX_buffer[10] = frame->data5;//
        TX_buffer[11] = frame->data6;//
        TX_buffer[12] = frame->data7;//
        debug_printf("init buffer done\r\n");
    do{
        Status = read_register(frame->can_addr, SJA_SR);
    }while(Status & RS_BIT); // SR.4 = 1 receiving , wait
    debug_printf("SR4 OK\r\n");
    do{
        Status = read_register(can_addr, SJA_SR);
    }while(!(Status & TCS_BIT)); // SR.3 = 0 transfering , wait
    debug_printf("SR3 OK\r\n");
    do{
        Status = read_register(can_addr, SJA_SR);
    }while(!(Status & TBS_BIT)); //SR.2 = 0, transfer reg is locked, wait
    debug_printf("SR2 OK\r\n");
    // transfer data to buffer
    write_register(can_addr, SJA_TBSR2, TX_buffer[2]);
    write_register(can_addr, SJA_TBSR3, TX_buffer[3]);
    write_register(can_addr, SJA_TBSR4, TX_buffer[4]);
    write_register(can_addr, SJA_TBSR5, TX_buffer[5]);
    write_register(can_addr, SJA_TBSR1, TX_buffer[1]);
    write_register(can_addr, SJA_TBSR0, TX_buffer[0]);
    write_register(can_addr, SJA_TBSR6, TX_buffer[6]);
    write_register(can_addr, SJA_TBSR7, TX_buffer[7]);
    write_register(can_addr, SJA_TBSR8, TX_buffer[8]);
    write_register(can_addr, SJA_TBSR9, TX_buffer[9]);
    write_register(can_addr, SJA_TBSR10, TX_buffer[10]);
    write_register(can_addr, SJA_TBSR11, TX_buffer[11]);
    write_register(can_addr, SJA_TBSR12, TX_buffer[12]);

    //request to transer
    write_register(can_addr, SJA_CMR, TR_BIT | AT_BIT);
    //write_register(can_addr, SJA_CMR, 0x01);
    microblaze_disable_interrupts();
    debug_printf("tx done\r\n");
    microblaze_enable_interrupts();
}

struct can_data_frame initialize_can_data_frame(addr1,addr2,addr3,can_addr) {
    struct can_data_frame frame = {
        .data_mode = PELI,
        .addr1 = addr1,
        .addr2 = addr2,
        .addr3 = addr3,
        .config_code = CAN_CONFIG,
        .data0 = 0x11,
        .data1 = 0x22,
        .data2 = 0x33,
        .data3 = 0x44,
        .data4 = 0x55,
        .data5 = 0x66,
        .data6 = 0x77,
        .data7 = 0x88,
		.can_addr = can_addr
    };
    return frame;
}


void can_rxd_frame(struct can_data_frame *frame){
    uint8_t Status;
    uint8_t Rxd_data;
    uint32_t can_addr = frame->can_addr;

    Status = read_register(can_addr, SJA_IR);

    if(Status & RI_BIT){
        debug_printf("DETECTED RXD MSG\r\n");
        RX_buffer[0] =   read_register(can_addr, SJA_RBSR0);
        RX_buffer[1] =   read_register(can_addr, SJA_RBSR1);
        RX_buffer[2] =   read_register(can_addr, SJA_RBSR2);
        RX_buffer[3] =   read_register(can_addr, SJA_RBSR3);
        RX_buffer[4] =   read_register(can_addr, SJA_RBSR4);

        RX_buffer[5] =   read_register(can_addr, SJA_RBSR5);
        RX_buffer[6] =   read_register(can_addr, SJA_RBSR6);
        RX_buffer[7] =   read_register(can_addr, SJA_RBSR7);
        RX_buffer[8] =   read_register(can_addr, SJA_RBSR8);

        RX_buffer[9] =   read_register(can_addr, SJA_RBSR9);
        RX_buffer[10] =  read_register(can_addr, SJA_RBSR10);
        RX_buffer[11] =  read_register(can_addr, SJA_RBSR11);
        RX_buffer[12] =  read_register(can_addr, SJA_RBSR12);

        write_register(can_addr, SJA_CMR, RRB_BIT); // release receive register
        Status = read_register(can_addr, SJA_ALC); // release judge catch
        Status = read_register(can_addr, SJA_ECC); // release error catch
    }

        // sometimes the data will be disordered
        // so we need to reorganize the data
        // find 0x88, this should be the 0th byte
        // reorganize the data
        for(int i = 0; i < FrameNum; i++){
            if((RX_buffer[i] == PELI) && (RX_buffer[i+4] == CAN_CONFIG)){
                for(int j = 0; j < FrameNum; j++){
                    frame->data_mode = RX_buffer[i];
                    frame->addr1 = RX_buffer[i+1];
                    frame->addr2 = RX_buffer[i+2];
                    frame->addr3 = RX_buffer[i+3];
                    frame->config_code = RX_buffer[i+4];

                    frame->data0 = RX_buffer[i+5]  ;
                    frame->data1 = RX_buffer[i+6]  ;
                    frame->data2 = RX_buffer[i+7]  ;
                    frame->data3 = RX_buffer[i+8]  ;
                    frame->data4 = RX_buffer[i+9]  ;
                    frame->data5 = RX_buffer[i+10] ;
                    frame->data6 = RX_buffer[i+11] ;
                    frame->data7 = RX_buffer[i+12] ;
                }
                // if we find the data, we can break the loop
                break;
            }
        }

        // frame->data_mode = RX_buffer[0];
        // frame->addr1 = RX_buffer[1];
        // frame->addr2 = RX_buffer[2];
        // frame->addr3 = RX_buffer[3];
        // frame->config_code = RX_buffer[4];

        // frame->data0 = RX_buffer[5]  ;
        // frame->data1 = RX_buffer[6]  ;
        // frame->data2 = RX_buffer[7]  ;
        // frame->data3 = RX_buffer[8]  ;
        // frame->data4 = RX_buffer[9]  ;
        // frame->data5 = RX_buffer[10] ;
        // frame->data6 = RX_buffer[11] ;
        // frame->data7 = RX_buffer[12] ;

    write_register(can_addr, SJA_IER, RIE_BIT);// enable rx irq


    Rxd_data = RX_buffer[7];


    debug_printf("rx done\r\n");
    debug_printf("rxd data = %d\r\n", Rxd_data);
}

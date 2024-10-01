#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "sleep.h"
#include "xil_exception.h"
#include "xdebug.h"
#include "xparameters.h"
#include "xintc.h"
#include "xuartlite.h"
#include "xuartlite_l.h"
#include "xgpio.h"
#include "xil_cache.h"

#include "xtmrctr.h"
#include "sleep.h"
#include "xmbox.h"

#include "can_drv.h"

#include <string.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_DATA_LENGTH 50

/*
 * AXI DEVICE DEFINE
 * */
// UART
#define UART_DEVICE_ID XPAR_UARTLITE_0_DEVICE_ID	//ID
#define UART_INTR_ID   XPAR_INTC_0_UARTLITE_0_VEC_ID//0U
#define RX_NOEMPTY     XUL_SR_RX_FIFO_VALID_DATA
// INTC
#define INTC_ID        XPAR_MICROBLAZE_0_AXI_INTC_DEVICE_ID
// TIMER
#define TMRCTR_DEVICE_ID    XPAR_MB0_T1_DEVICE_ID
#define TMRCTR_INTR_ID      XPAR_INTC_0_TMRCTR_1_VEC_ID	//1U
// LED
#define LED_DEVICE_ID XPAR_MB0_GPIO_LED_DEVICE_ID
// MB0_DOS_CMD
#define DOS_CMD_GPIO_DEVICE_ID XPAR_MB0_DOS_CMD_DEVICE_ID
// MAIL BOX0
#define MAIL_BOX_0_ID XPAR_MBOX_0_DEVICE_ID
#define MAIL_BOX_0_INTR_ID XPAR_INTC_0_MBOX_0_VEC_ID
// CAN Controller
#define CAN_0_BASEADDR XPAR_CAN_CONTROLLER_0_S00_AXI_BASEADDR
#define CAN_1_BASEADDR XPAR_CAN_CONTROLLER_1_S00_AXI_BASEADDR
#define CAN_0_INTR_ID XPAR_INTC_0_CAN_CONTROLLER_0_VEC_ID
#define CAN_1_INTR_ID XPAR_INTC_0_CAN_CONTROLLER_1_VEC_ID
// FINN OUTPUT
#define FINN_IN_DEVICE_ID XPAR_MB0_FINN_IN_DEVICE_ID
// ATK OUTPUT
#define ATK_FLAG_DEVICE_ID XPAR_AXI_GPIO_ATKFLAG_DEVICE_ID


#define DEBUG_MODE 0

#if DEBUG_MODE
#define debug_printf(fmt, ...) print(stderr, fmt, __VA_ARGS__)
#else
#define debug_printf(fmt, ...) do {} while (0)
#endif


/*
 * AXI DECIVE INSTANCE
 * */

static XIntc Intc;
static XUartLite Uart;
static XTmrCtr  Timer;
static XGpio GpioOutput;
static XGpio GpioOutput2;
static XGpio GpioOutput3;
static XGpio GpioInput;
static XMbox Mbox0;
static XMbox_Config * XMbox0_ConfigPtr;



/*
 * Structure
 * */
struct can_data_frame trans_frame;
struct can_data_frame recv_frame;


static char command[MAX_COMMAND_LENGTH];
static u32 command_index = 0;

/**
 * Variables
 * */

volatile uint32_t interrupt_counter = 0;
bool ready_inject = 0;
bool dos_cmd = false;
u32 switch_state_last = 0;

/*
 * FUNCTION DECLARE
 * */

// IRQ handler
void uart_handler(void *CallbackRef);
void timer_intr_hander(void *InstancePtr);
void mailbox0_intr_handler(void *InstancePtr);
void can_0_irq_handler(void *InstancePtr);
void can_1_irq_handler(void *InstancePtr);
uint8_t construct_uint8(char high, char low);

// General Functions

void mailbox_init(){
	debug_printf("Initialize mailbox0 \r\n");
	XMbox0_ConfigPtr = XMbox_LookupConfig(MAIL_BOX_0_ID);
	XMbox_CfgInitialize(&Mbox0, XMbox0_ConfigPtr, XMbox0_ConfigPtr->BaseAddress);
    XIntc_Connect(&Intc, MAIL_BOX_0_INTR_ID,(XInterruptHandler)mailbox0_intr_handler, &Mbox0);

}

void uart_init(){
	debug_printf("Initialize UART \r\n");
    XUartLite_Initialize(&Uart , UART_DEVICE_ID);
    XIntc_Connect(&Intc, UART_INTR_ID,(XInterruptHandler)uart_handler,&Uart);
    XUartLite_EnableInterrupt(&Uart);
}

void timer_init(){
	debug_printf("Initialize timer \r\n");
    XTmrCtr_Initialize(&Timer, TMRCTR_DEVICE_ID);
    XTmrCtr_SetOptions(&Timer, 0,XTC_INT_MODE_OPTION |    //interrupt
                                 XTC_AUTO_RELOAD_OPTION | //auto load
                                 XTC_DOWN_COUNT_OPTION);  //decrease
    XTmrCtr_SetResetValue(&Timer, 0, 50000);
    XTmrCtr_SetHandler(&Timer, timer_intr_hander,&Timer);
    XTmrCtr_Start(&Timer, 0);	//start timer
    XIntc_Connect(&Intc, TMRCTR_INTR_ID,
                  (XInterruptHandler)XTmrCtr_InterruptHandler,&Timer);
}

void intc_init(){
	print("Initialize interrupt controller \r\n");
    XIntc_Initialize(&Intc, INTC_ID);
}

void cache_init(){
	print("Initialize Cache \r\n");
	Xil_ICacheEnable();
	Xil_DCacheEnable();
}

void gpio_init(){
	print("Initialize GPIO \r\n");
	XGpio_Initialize(&GpioOutput, XPAR_MB0_GPIO_LED_DEVICE_ID);
	XGpio_SetDataDirection(&GpioOutput, 1, 0x0);

	XGpio_Initialize(&GpioOutput2, DOS_CMD_GPIO_DEVICE_ID);
	XGpio_SetDataDirection(&GpioOutput2, 1, 0x0);

    XGpio_Initialize(&GpioInput, FINN_IN_DEVICE_ID);
    XGpio_SetDataDirection(&GpioInput, 1, 0xFFFFFFFF);

	XGpio_Initialize(&GpioOutput3, ATK_FLAG_DEVICE_ID);
	XGpio_SetDataDirection(&GpioOutput3, 1, 0x0);


}

void intc_setup(){
	print("Initialize interrupt setup \r\n");
    XIntc_Start(&Intc, XIN_REAL_MODE);	//start INTC controller
    // Interrupt instance begin
    XIntc_Enable(&Intc,UART_INTR_ID);
    XIntc_Enable(&Intc,TMRCTR_INTR_ID);
    XIntc_Enable(&Intc,MAIL_BOX_0_INTR_ID);
    XIntc_Enable(&Intc,CAN_0_INTR_ID);
    XIntc_Enable(&Intc,CAN_1_INTR_ID);
    // Interrupt instance end
    Xil_ExceptionInit();
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
	(Xil_ExceptionHandler)XIntc_InterruptHandler , &Intc);
	Xil_ExceptionEnable();
}

void can_device_init(){
	can_init(CAN_0_BASEADDR);
	can_init(CAN_1_BASEADDR);
	XIntc_Connect(&Intc, CAN_0_INTR_ID,(XInterruptHandler)can_0_irq_handler, NULL);
	XIntc_Connect(&Intc, CAN_1_INTR_ID,(XInterruptHandler)can_1_irq_handler, NULL);
}

void device_init(){
	print("Initialize Device \r\n");
	intc_init();
	mailbox_init();
	uart_init();
	timer_init();

	cache_init();
	gpio_init();
	can_device_init();

	intc_setup();
}

/* reorder the msg rcv from the uart*/
bool parse_command(const char *command, u8 *data, u32 *length) {
    const char *start_marker = "#";
    const char *end_marker = "$";
    const char *start_pos = strstr(command, start_marker);
    const char *end_pos = strstr(command, end_marker);
    
    if (start_pos != NULL && end_pos != NULL && start_pos < end_pos) {
        start_pos += strlen(start_marker);
        *length = (u32)(end_pos - start_pos);
        if (*length <= MAX_DATA_LENGTH) {
            memcpy(data, start_pos, *length);
            return true;
        }
    }
    return false;
}


int main()
{
    struct can_data_frame *inject_frame = malloc(sizeof(struct can_data_frame));

    // 初始化结构体成员
    inject_frame->data_mode = 0; // 设置数据模式
    inject_frame->addr1 = 0; // 设置数据地址1
    inject_frame->addr2 = 0; // 设置数据地址2
    inject_frame->addr3 = 0; // 设置数据地址3
    inject_frame->config_code = 0; // 设置配置码
    inject_frame->data0 = 0; // 设置数据0
    inject_frame->data1 = 0; // 设置数据1
    inject_frame->data2 = 0; // 设置数据2
    inject_frame->data3 = 0; // 设置数据3
    inject_frame->data4 = 0; // 设置数据4
    inject_frame->data5 = 0; // 设置数据5
    inject_frame->data6 = 0; // 设置数据6
    inject_frame->data7 = 0; // 设置数据7
    inject_frame->can_addr = 0; // 设置CAN控制器地址

    init_platform();
    //enable_caches();
    //init_uart();
    print("Control Node Started to work\n\r");
    print("test version\n\r");
    //print("Successfully ran Hello World application");
    device_init();



    trans_frame = initialize_can_data_frame(MB0_CAN0_ID, MB0_CAN0_ID, MB0_CAN0_ID, CAN_0_BASEADDR);
    trans_frame.data2 = 0x02;
	recv_frame = initialize_can_data_frame(MB0_CAN0_ID, MB0_CAN0_ID, MB0_CAN0_ID, CAN_1_BASEADDR);

    while(1){

        u32 switch_state;
        switch_state = XGpio_DiscreteRead(&GpioInput, 1);
        if((switch_state != 0) && (switch_state !=switch_state_last)){
            printf("atk detected--------------");

            switch (switch_state) {
                case 1:
                    printf("atk type: DoS\r\n");
                    break;
                case 2:
                	printf("atk type: Fuzzing\r\n");
                    break;
                case 3:
                	printf("atk type: Spoofing\r\n");
                    break;
                default:
                	break;
            }

        }
        switch_state_last = switch_state;
		if(ready_inject){
			inject_frame->can_addr = CAN_0_BASEADDR;
			inject_frame->data_mode = construct_uint8(command[1],command[2]);
			inject_frame->addr1 = construct_uint8(command[3],command[4]);
			inject_frame->addr2 = construct_uint8(command[5],command[6]);
			inject_frame->addr3 = construct_uint8(command[7],command[8]);
			inject_frame->config_code = construct_uint8(command[9],command[10]);
		 // init data
			inject_frame->data0 = construct_uint8(command[11],command[12]);
			inject_frame->data1 = construct_uint8(command[13],command[14]);
			inject_frame->data2 = construct_uint8(command[15],command[16]);
			inject_frame->data3 = construct_uint8(command[17],command[18]);
			inject_frame->data4 = construct_uint8(command[19],command[20]);
			inject_frame->data5 = construct_uint8(command[21],command[22]);
			inject_frame->data6 = construct_uint8(command[23],command[24]);
			inject_frame->data7 = construct_uint8(command[25],command[26]);
			can_txd_frame(inject_frame);
			XGpio_DiscreteWrite(&GpioOutput3, 1, 0x01);
			ready_inject = false;
			XGpio_DiscreteWrite(&GpioOutput3, 1, 0x00);
			//printf("injected\n");
		}


    }
    //disable_caches();
    cleanup_platform();
    return 0;
}

uint8_t construct_uint8(char high, char low) {
    uint8_t high_val = (high >= 'a' && high <= 'f') ? (high - 'a' + 10) : (high - '0');
    uint8_t low_val = (low >= 'a' && low <= 'f') ? (low - 'a' + 10) : (low - '0');
    uint8_t result = (high_val << 4) | low_val;
//    uint8_t result = 0x00;
    return result;
}


void uart_handler(void *CallbackRef) {
    u8 Read_data[MAX_COMMAND_LENGTH];
    u32 isr_status;
    XUartLite *InstancePtr= (XUartLite *)CallbackRef;

    // Read Uart Status register
    isr_status = XUartLite_ReadReg(InstancePtr->RegBaseAddress, XUL_STATUS_REG_OFFSET);
    // check rcv buffer is not empty
    if (isr_status & RX_NOEMPTY) {
        char received_char = XUartLite_ReadReg(InstancePtr->RegBaseAddress, XUL_RX_FIFO_OFFSET);

//		if (received_char == '*'){
//			dos_cmd = true;
//		}
        // check command start with # and clear the buffer
        if (received_char == '#' && command_index == 0) {
            memset(command, 0, sizeof(command));
            command[0] = received_char;
            command_index = 1;
        } else if (command_index > 0) {
            command[command_index++] = received_char;
            // check if receive end flag
            if (received_char == '$') {
                u8 data[MAX_DATA_LENGTH];
                u32 data_length;
                if (parse_command(command, data, &data_length)) {
                	ready_inject = true;
				 	printf("ready inject\n");
                }
                // 重置命令缓冲区
                //memset(command, 0, sizeof(command));
                command_index = 0;
            }
        } else if(received_char == '*'){
        	dos_cmd = true;
        }
        // 将接收到的字符回传
        //XUartLite_WriteReg(InstancePtr->RegBaseAddress, XUL_TX_FIFO_OFFSET, received_char);
    }
}
void timer_intr_hander(void *InstancePtr)
{
    static int led_state = 0x00;
    // ONE CYCLE
    if (XTmrCtr_IsExpired(&Timer, 0)){
        interrupt_counter++;
        // 2s
        if (interrupt_counter % 200 == 0) {
        	debug_printf("Control Node Is Alive\r\n");
        }
        // 0.2s
        if (interrupt_counter % 500 == 0) {
        	led_state = ~led_state;
            XGpio_DiscreteWrite(&GpioOutput, 1, led_state);
        }
        if(dos_cmd){
            if (interrupt_counter % 500 == 0) {
                XGpio_DiscreteWrite(&GpioOutput2, 1, 0x01);
            }
            if (interrupt_counter % 700 == 0) {
                XGpio_DiscreteWrite(&GpioOutput2, 1, 0x00);
                dos_cmd = false;
            }
        }


    }

}

void mailbox0_intr_handler(void *InstancePtr)
{
	char RcvMsg[32];
	char str[] = "msgbmsgb";
	XMbox_ReadBlocking(&Mbox0, (u32*)(RcvMsg), strlen(str));
	debug_printf("receive msb from msgbox1");
	debug_printf("%s\r\n", RcvMsg);
}
void can_0_irq_handler(void *InstancePtr){
	can_rxd(CAN_0_BASEADDR);
}
void can_1_irq_handler(void *InstancePtr){
	can_rxd_frame(&recv_frame);
	printf("listen:%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\n",
			recv_frame.data_mode,
			recv_frame.addr1,
			recv_frame.addr2,
			recv_frame.addr3,
			recv_frame.config_code,
			recv_frame.data0,
			recv_frame.data1,
			recv_frame.data2,
			recv_frame.data3,
			recv_frame.data4,
			recv_frame.data5,
			recv_frame.data6,
			recv_frame.data7);

}


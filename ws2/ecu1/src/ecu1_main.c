#include <stdio.h>

#include "xil_printf.h"
#include "sleep.h"
#include "xil_exception.h"
#include "xdebug.h"
#include "xparameters.h"
#include "xintc.h"

#include "xgpio.h"
#include "xil_cache.h"

#include "xtmrctr.h"
#include "sleep.h"
//#include "xmbox.h"

#include "can_drv.h"

/*
 * AXI DEVICE DEFINE
 * */
// INTC
#define INTC_ID        XPAR_MICROBLAZE_1_AXI_INTC_DEVICE_ID
// TIMER
#define TMRCTR_DEVICE_ID    XPAR_MB1_T1_DEVICE_ID
#define TMRCTR_INTR_ID      XPAR_INTC_0_TMRCTR_1_VEC_ID	//1U
// LED
#define LED_DEVICE_ID XPAR_MB1_GPIO_LED_DEVICE_ID
// CAN Controller
#define CAN_0_BASEADDR XPAR_MB1_CAN_CONTROLLER_S00_AXI_BASEADDR
#define CAN_0_INTR_ID XPAR_INTC_0_CAN_CONTROLLER_0_VEC_ID



/*
 * AXI DECIVE INSTANCE
 * */

static XIntc Intc;
static XTmrCtr  Timer;
static XGpio GpioOutput;

/*
 * Structure
 * */
struct can_data_frame trans_frame;
struct can_data_frame recv_frame;


/**
 * Variables
 * */

volatile uint32_t interrupt_counter = 0;
volatile uint8_t report_life_flag = 0;


/**
 * Protocal Data Define
 * */

uint8_t pack[8] = {0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04};
uint8_t life_signal = 0x00;
uint8_t life_val[40] = {0xAB, 0xE3, 0xBA, 0x38,
                       0xAC, 0xE4, 0xBB, 0x39,
                       0xAA, 0xE2, 0xB9, 0x37,
                       0xAD, 0xE5, 0xBC, 0x3A,
                       0xA9, 0xE1, 0xB8, 0x36,
                       0xAE, 0xE6, 0xBD, 0x3B,
                       0xAF, 0xE7, 0xBE, 0x3C,
                       0xA8, 0xE0, 0xB7, 0x35,
                       0xA7, 0xEF, 0xB6, 0x34,
                       0xA6, 0xEE, 0xB5, 0x33,};
bool ECU_Status = true;
bool TCU_Status = true;
bool Braker_Status = false;

/*
 * FUNCTION DECLARE
 * */

// IRQ handler

void timer_intr_handler(void *InstancePtr);
void can_0_irq_handler(void *InstancePtr);

// General Functions

void timer_init(){

    XTmrCtr_Initialize(&Timer, TMRCTR_DEVICE_ID);
    XTmrCtr_SetOptions(&Timer, 0,XTC_INT_MODE_OPTION |    //interrupt
                                 XTC_AUTO_RELOAD_OPTION | //auto load
                                 XTC_DOWN_COUNT_OPTION);  //decrease
    XTmrCtr_SetResetValue(&Timer, 0, 50000);
    XTmrCtr_SetHandler(&Timer, timer_intr_handler,&Timer);
    XTmrCtr_Start(&Timer, 0);	//start timer
    XIntc_Connect(&Intc, TMRCTR_INTR_ID,
                  (XInterruptHandler)XTmrCtr_InterruptHandler,&Timer);
}

void intc_init(){
	print("Initialize interrupt controller \r\n");
    XIntc_Initialize(&Intc, INTC_ID);
}

void cache_init(){
	print("Initialize GPIO \r\n");
	Xil_ICacheEnable();
	Xil_DCacheEnable();
}

void gpio_init(){
	print("Initialize GPIO \r\n");
	XGpio_Initialize(&GpioOutput, LED_DEVICE_ID);
	XGpio_SetDataDirection(&GpioOutput, 1, 0x0);
}

void intc_setup(){
	print("Initialize interrupt setup \r\n");
    XIntc_Start(&Intc, XIN_REAL_MODE);	//start INTC controller
    // Interrupt instance begin
    XIntc_Enable(&Intc,TMRCTR_INTR_ID);
    XIntc_Enable(&Intc,CAN_0_INTR_ID);
    // Interrupt instance end
    Xil_ExceptionInit();
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
	(Xil_ExceptionHandler)XIntc_InterruptHandler , &Intc);
	Xil_ExceptionEnable();
}

void can_device_init(){
	can_init(CAN_0_BASEADDR);
	XIntc_Connect(&Intc, CAN_0_INTR_ID,(XInterruptHandler)can_0_irq_handler, NULL);
}

void device_init(){
	print("Initialize Device \r\n");
	intc_init();

	timer_init();
	cache_init();
	gpio_init();
	can_device_init();
	intc_setup();
}

void update_status(struct can_data_frame *frame){
    /* pack data upgrade*/
    pack[0] = life_val[life_signal % 40];
    pack[1] = (ECU_Status ? 0x01 : 0x00) | (pack[1] & 0xFE);
    pack[2] = (TCU_Status ? 0x01 : 0x00) | (pack[2] & 0xFE);
    pack[3] = (Braker_Status ? 0x01 : 0x00) | (pack[3] & 0xFE);
    /* struct data upgrade*/
    frame->data0 = pack[0];
    frame->data1 = pack[1];
    frame->data2 = pack[2];
    frame->data3 = pack[3];
    frame->data4 = pack[4];
    frame->data5 = pack[5];
    frame->data6 = pack[6];
    frame->data7 = pack[7];
}

void ecu_process_logic(struct can_data_frame *frame){
    /* if receive ECU3 Collision Detector*/
    if((frame->addr1 == MB3_CAN0_ID) && (frame->data1 & 0x01) && (frame->data4 & 0x01)){
        /* Self Execute*/
            /* ECU Stop*/
            ECU_Status = 0x00;
            /* TCU Stop*/
            TCU_Status = 0x00;
    }else if((frame->addr1 == MB3_CAN0_ID) && (!(frame->data1 & 0x01))  && (frame->data4 & 0x01)){
            /* ECU Stop*/
            ECU_Status = 0x01;
            /* TCU Stop*/
            TCU_Status = 0x01;
    }
    /* if receive ECU3 Collision Detector*/
    if((frame->addr1 == MB3_CAN0_ID) && (frame->data2 & 0x01)  && (frame->data4 & 0x01)){
        /* Self Execute*/
            /* Braker excute*/
            Braker_Status = 0x01;
    }else if((frame->addr1 == MB3_CAN0_ID) && (!(frame->data2 & 0x01))  && (frame->data4 & 0x01)){
        /* Self Execute*/
            /* Braker excute*/
            Braker_Status = 0x00;
    }
}



int main()
{
    device_init();

    // CAN FRAME INIT
    trans_frame = initialize_can_data_frame(MB1_CAN0_ID, MB1_CAN0_ID, MB1_CAN0_ID, CAN_0_BASEADDR);
	recv_frame = initialize_can_data_frame(MB1_CAN0_ID, MB1_CAN0_ID, MB1_CAN0_ID, CAN_0_BASEADDR);

    update_status(&trans_frame);
    while(1){
        update_status(&trans_frame);
    	if(report_life_flag){
            can_txd_frame(&trans_frame);
            report_life_flag = 0;
    	}
        life_signal ++;
    }


    return 0;
}



void timer_intr_handler(void *InstancePtr)
{
    static int led_state = 0x00;
    // ONE CYCLE
    if (XTmrCtr_IsExpired(&Timer, 0)){
        interrupt_counter++;
        // 6s
        if (interrupt_counter % 600 == 0) {
            //printf("ECU1 Is Alive\r\n");
            report_life_flag = 1;
        }
        // 0.2s
        if (interrupt_counter % 500 == 0) {
        	led_state = ~led_state;
            XGpio_DiscreteWrite(&GpioOutput, 1, led_state);
        }
    }

}
void can_0_irq_handler(void *InstancePtr){
	can_rxd_frame(&recv_frame);
    ecu_process_logic(&recv_frame);
	//printf("C\r\n");
}

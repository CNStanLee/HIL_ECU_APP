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
#include <stdlib.h>
#include "xparameters.h"
#include "xil_printf.h"
#include "sleep.h"
#include "xil_exception.h"
#include "xdebug.h"
#include "xil_cache.h"
#include "sleep.h"
#include <math.h>
#include <stdint.h>
#include "finn_driver.h"
#include "xgpio.h"

#include "can_drv.h"
#include "sleep.h"

#include <string.h>
#include <stdbool.h>
#include "xintc.h"



/*
 * AXI DEVICE DEFINE
 * */

// INTC
#define INTC_ID        XPAR_MICROBLAZE_4_AXI_INTC_DEVICE_ID
// FINN OUTPUT
#define FINN_OUTPUT_DEVICE_ID XPAR_MB5_FINN_OUT_DEVICE_ID
// CAN Controller
#define CAN_0_BASEADDR XPAR_MB_FINN_CAN_CONTROLLER_S00_AXI_BASEADDR
#define CAN_0_INTR_ID XPAR_INTC_0_CAN_CONTROLLER_0_VEC_ID



/*
 * AXI DECIVE INSTANCE
 * */
static XIntc Intc;
static XGpio GpioOutput;


/*
 * Structure
 * */
struct can_data_frame trans_frame;
struct can_data_frame recv_frame1;
struct can_data_frame recv_frame2;
struct can_data_frame recv_frame3;
struct can_data_frame recv_frame4;

/*
 * Variable define
 * */


// input dos message
// 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0
uint8_t input_dos[40] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0};  
// input fuzzing message
// 5.0,22.0,207.0,78.0,156.0,167.0,104.0,180.0,233.0,99.0,2.0,31.0,144.0,254.0,250.0,205.0,11.0,66.0,253.0,58.0,2.0,9.0,0.0,33.0,16.0,255.0,0.0,255.0,0.0,0.0,4.0,4.0,161.0,44.0,189.0,26.0,26.0,73.0,85.0,24.0
uint8_t input_fuzzing[40] = {0x05, 0x16, 0xCF, 0x4E, 0x9C, 0xA7, 0x68, 0xB4, 0xE9, 0x63,
                                0x02, 0x1F, 0x90, 0xFE, 0xFA, 0xCD, 0x0B, 0x42, 0xFD, 0x3A,
                                0x02, 0x09, 0x00, 0x21, 0x10, 0xFF, 0x00, 0xFF, 0x00, 0x00,
                                0x04, 0x04, 0xA1, 0x2C, 0xBD, 0x1A, 0x1A, 0x49, 0x55, 0x18};
// input RPM-Spoofing message
// 1.0,16.0,127.0,133.0,0.0,0.0,35.0,0.0,0.0,0.0,6.0,11.0,69.0,41.0,36.0,255.0,41.0,36.0,0.0,255.0,6.0,8.0,5.0,32.0,116.0,104.0,117.0,0.0,0.0,76.0,6.0,11.0,69.0,41.0,36.0,255.0,41.0,36.0,0.0,255.0
uint8_t input_rpm_spoofing[40] = {0x01, 0x10, 0x7F, 0x85, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00,
                                    0x06, 0x0B, 0x45, 0x29, 0x24, 0xFF, 0x29, 0x24, 0x00, 0xFF,
                                    0x06, 0x08, 0x05, 0x20, 0x74, 0x68, 0x75, 0x00, 0x00, 0x4C,
                                    0x06, 0x0B, 0x45, 0x29, 0x24, 0xFF, 0x29, 0x24, 0x00, 0xFF};

// input data buffer
uint8_t input_data_buffer_c[40] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0}; 

//define a 2d array (4 x 10), initialize all elements to 0
uint8_t input_data_buffer[4][10] = {0};
uint8_t input_data_counter = 0;
bool finn_data_ready = false;


/*
 * FUNCTION DECLARE
 * */

// IRQ handler
void can_0_irq_handler(void *InstancePtr);


void intc_init(){

    XIntc_Initialize(&Intc, INTC_ID);
}


void cache_init(){
	Xil_ICacheEnable();
	Xil_DCacheEnable();
}


void gpio_init(){

	XGpio_Initialize(&GpioOutput, FINN_OUTPUT_DEVICE_ID);
	XGpio_SetDataDirection(&GpioOutput, 1, 0x0);
}


void intc_setup(){

    XIntc_Start(&Intc, XIN_REAL_MODE);	//start INTC controller
    // Interrupt instance begin

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
	cache_init();
    gpio_init();
	can_device_init();

	intc_setup();
}

// This main function is for the standard test application
//  int main ()
//  {
//     // initialize the devices
//     device_init();

//     recv_frame = initialize_can_data_frame(MB0_CAN0_ID, MB0_CAN0_ID, MB0_CAN0_ID, CAN_0_BASEADDR);

//     while (1) {
//         int8_t test_result[3] = {0, 0, 0};
//         test_result[0] = call_finn(input_dos);
//         XGpio_DiscreteWrite(&GpioOutput, 1, test_result[0]);
//         test_result[1] = call_finn(input_fuzzing);
//         XGpio_DiscreteWrite(&GpioOutput, 1, test_result[1]);
//         test_result[2] = call_finn(input_rpm_spoofing);
//         XGpio_DiscreteWrite(&GpioOutput, 1, test_result[2]);
//         printf("%d,%d,%d", test_result[0], test_result[1], test_result[2]);
//     }
//     return 0;
//  }

 void parse_data(){
    input_data_buffer_c[0] = recv_frame1.addr1;
    input_data_buffer_c[1] = recv_frame1.addr2;
    input_data_buffer_c[2] = recv_frame1.data0;
    input_data_buffer_c[3] = recv_frame1.data1;
    input_data_buffer_c[4] = recv_frame1.data2;
    input_data_buffer_c[5] = recv_frame1.data3;
    input_data_buffer_c[6] = recv_frame1.data4;
    input_data_buffer_c[7] = recv_frame1.data5;
    input_data_buffer_c[8] = recv_frame1.data6;
    input_data_buffer_c[9] = recv_frame1.data7;
    input_data_buffer_c[10] = recv_frame2.addr1;
    input_data_buffer_c[11] = recv_frame2.addr2;
    input_data_buffer_c[12] = recv_frame2.data0;
    input_data_buffer_c[13] = recv_frame2.data1;
    input_data_buffer_c[14] = recv_frame2.data2;
    input_data_buffer_c[15] = recv_frame2.data3;
    input_data_buffer_c[16] = recv_frame2.data4;
    input_data_buffer_c[17] = recv_frame2.data5;
    input_data_buffer_c[18] = recv_frame2.data6;
    input_data_buffer_c[19] = recv_frame2.data7;
    input_data_buffer_c[20] = recv_frame3.addr1;
    input_data_buffer_c[21] = recv_frame3.addr2;
    input_data_buffer_c[22] = recv_frame3.data0;
    input_data_buffer_c[23] = recv_frame3.data1;
    input_data_buffer_c[24] = recv_frame3.data2;
    input_data_buffer_c[25] = recv_frame3.data3;
    input_data_buffer_c[26] = recv_frame3.data4;
    input_data_buffer_c[27] = recv_frame3.data5;
    input_data_buffer_c[28] = recv_frame3.data6;
    input_data_buffer_c[29] = recv_frame3.data7;
    input_data_buffer_c[30] = recv_frame4.addr1;
    input_data_buffer_c[31] = recv_frame4.addr2;
    input_data_buffer_c[32] = recv_frame4.data0;
    input_data_buffer_c[33] = recv_frame4.data1;
    input_data_buffer_c[34] = recv_frame4.data2;
    input_data_buffer_c[35] = recv_frame4.data3;
    input_data_buffer_c[36] = recv_frame4.data4;
    input_data_buffer_c[37] = recv_frame4.data5;
    input_data_buffer_c[38] = recv_frame4.data6;
    input_data_buffer_c[39] = recv_frame4.data7;
 }


//  feed the data on the bus into finn accelerator
 int main ()
 {
    // initialize the devices
    device_init();

    recv_frame1 = initialize_can_data_frame(MB0_CAN0_ID, MB0_CAN0_ID, MB0_CAN0_ID, CAN_0_BASEADDR);
    recv_frame2 = initialize_can_data_frame(MB0_CAN0_ID, MB0_CAN0_ID, MB0_CAN0_ID, CAN_0_BASEADDR);
    recv_frame3 = initialize_can_data_frame(MB0_CAN0_ID, MB0_CAN0_ID, MB0_CAN0_ID, CAN_0_BASEADDR);
    recv_frame4 = initialize_can_data_frame(MB0_CAN0_ID, MB0_CAN0_ID, MB0_CAN0_ID, CAN_0_BASEADDR);

    int8_t test_result = 0;
    while (1) {
        if(finn_data_ready){
            // transfer input_data_buffer to 40 bytes input data by connect the data
            parse_data();
            test_result = call_finn(input_data_buffer_c);
            XGpio_DiscreteWrite(&GpioOutput, 1, test_result);   //send the result to the GPIO
            finn_data_ready = false;
            if(test_result != 0){
                printf("The result is %d", test_result);
            }
        }
    }
    return 0;
 }




 void can_0_irq_handler(void *InstancePtr){
    input_data_counter++;
    switch(input_data_counter){
    case 1:
        can_rxd_frame(&recv_frame1);
        break;
    case 2:
        can_rxd_frame(&recv_frame2);
        break;
    case 3:
        can_rxd_frame(&recv_frame3);
        break;
    case 4:
        input_data_counter = 0;
        finn_data_ready = true;
        can_rxd_frame(&recv_frame4);
        break;
    default:
        break;
    }

}



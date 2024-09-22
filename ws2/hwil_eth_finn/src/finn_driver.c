#include "finn_driver.h"
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "xparameters.h"
#include "xil_printf.h"
#include "sleep.h"
#include "xil_exception.h"
#include "xdebug.h"


#include "xil_cache.h"
#include "sleep.h"

#include <math.h>
#include <stdint.h>

// define CAN input data as 40 bytes
// CAN Message 1 + 2 + 3 + 4


void convert_u8_to_u32(uint8_t input[40], uint32_t output[10]) {
    if (input == NULL || output == NULL) {
        return;
    }
    for (int i = 0; i < 10; i++) {
        output[i] = (uint32_t)input[i * 4] |
                    ((uint32_t)input[i * 4 + 1] << 8) |
                    ((uint32_t)input[i * 4 + 2] << 16) |
                    ((uint32_t)input[i * 4 + 3] << 24);
    }
}

static void inline write_axis_10_u32(volatile uint32_t *a)
{

	//40 u8 means 10 u32
    if (a == NULL) {
        return;
    }

   register uint32_t a0, a1, a2, a3;
   register uint32_t a4, a5, a6, a7;
   register uint32_t a8, a9;



   a3  = a[3];  a1  = a[1];  a2  = a[2];  a0  = a[0];
   a7  = a[7];  a5  = a[5];  a6  = a[6];  a4  = a[4];
   a9  = a[9];  a8  = a[8];

   putfsl(a0,  1); putfsl(a1,  1); putfsl(a2,  1); putfsl(a3,  1);
   putfsl(a4,  1); putfsl(a5,  1); putfsl(a6,  1); putfsl(a7,  1);
   putfsl(a8,  1); putfsl(a9,  1);

}


void feed_data_to_finn(uint32_t features[10]){
    if (features == NULL) {
        return;
    }
    write_axis_10_u32(features);
}

static void inline read_axis_1_int32(volatile int32_t *a)
{
    if (a == NULL) {
        return;
    }
   register int32_t a0;

   getfsl(a0, 1);

   a[0] = a0;
}

void read_data_from_finn(int32_t *output){
    if (output == NULL) {
        return;
    }
    read_axis_1_int32(output);
    read_axis_1_int32(output + 1);
}

void calculate_result(int32_t *output, int16_t *res_int16){
    if (output == NULL || res_int16 == NULL) {
        return;
    }
    res_int16[0] = (int16_t)(output[0] & 0xFFFF);        
    res_int16[1] = (int16_t)((output[0] >> 16) & 0xFFFF);
    res_int16[2] = (int16_t)(output[1] & 0xFFFF);        
    res_int16[3] = (int16_t)((output[1] >> 16) & 0xFFFF);
}

void calculate_possibility(int16_t *res_int16, float *possibility_f32){

    if (res_int16 == NULL || possibility_f32 == NULL) {
        return;
    }

        float intermediate[4];
        float sum_exp = 0.0;
        float k = 0.03540867194533348;
        float bias[4] = {
            0.5202080607414246,
            -0.25941503047943115,
            -0.4128757119178772,
            -0.7262454628944397
        };
        float p1, p2, p3, p4;

        // Step 1: Multiply by k and add bias
        for (int i = 0; i < 4; i++) {
            intermediate[i] = res_int16[i] * k + bias[i];
        }

        // Step 2: Compute exponentials and their sum
        sum_exp = 0;
        for (int i = 0; i < 4; i++) {
            sum_exp += exp(intermediate[i]);
        }

        // Step 3: Compute softmax
        for (int i = 0; i < 4; i++) {
            possibility_f32[i] = exp(intermediate[i]) / sum_exp;
        }
        p1 = possibility_f32[0];
        p2 = possibility_f32[1];
        p3 = possibility_f32[2];
        p4 = possibility_f32[3];
        print("test");
}

int8_t compare_result(float *possibility_f32){
    if (possibility_f32 == NULL) {
        return -1; // Return an invalid index if the input is null
    }

    int8_t max_index = 0;
    float max_value = possibility_f32[0];
    for (int i = 1; i < 4; i++){
        if (possibility_f32[i] > max_value){
            max_value = possibility_f32[i];
            max_index = i;
        }
    }
	if(max_index != 0){
		printf("attack detected");
	}
    return max_index;
}

int8_t call_finn(uint8_t input[40]){

    if (input == NULL) {
        return -1; // Return an invalid index if the input is null
    }

    uint32_t features[10];
    int32_t output[2];
    int16_t res_int16[4];
    float possibility_f32[4];
    int8_t compare_result_int8 = 0;
    convert_u8_to_u32(input, features);
    feed_data_to_finn(features);
    //m_usleep(1);
    read_data_from_finn(output);
    calculate_result(output, res_int16);
    calculate_possibility(res_int16, possibility_f32);
    compare_result_int8 = compare_result(possibility_f32);
    return compare_result_int8;
}

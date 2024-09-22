/*
 * @Author: Changhongli lic9@tcd.com
 * @Date: 2024-06-11 15:23:24
 * @LastEditors: Changhongli lic9@tcd.com
 * @LastEditTime: 2024-06-11 17:08:26
 * @FilePath: /workspace/finn0610/src/finn_driver.h
 * @Description: 
 * 
 */
#ifndef __FINN_DRIVER_H_
#define __FINN_DRIVER_H_

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include "stdio.h"

void convert_u8_to_u32(uint8_t input[40], uint32_t output[10]);
void feed_data_to_finn(uint32_t features[10]);
void read_data_from_finn(int32_t *output);
void calculate_result(int32_t *output, int16_t *res_int16);
void calculate_result(int32_t *output, int16_t *res_int16);
void calculate_possibility(int16_t *res_int16, float *possibility_f32);
int8_t compare_result(float *possibility_f32);
int8_t call_finn(uint8_t input[40]);



#endif

#ifndef __GPIO_DRV_H_
#define __GPIO_DRV_H_

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>

extern uint32_t read_gpio_32(uint32_t addr);
extern void write_gpio_32(uint32_t addr, uint32_t value);
extern void write_gpio_8(uint32_t addr, uint32_t byte_offset, uint8_t value);
extern void write_gpio_1(uint32_t addr, uint32_t byte_offset, uint32_t bit_offset, uint8_t value);
extern uint8_t read_gpio_8(uint32_t addr, uint32_t byte_offset);
extern uint8_t read_gpio_1(uint32_t addr, uint32_t byte_offset, uint32_t bit_offset);
#endif

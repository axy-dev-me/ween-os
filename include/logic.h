#ifndef LOGIC_H
#define LOGIC_H

#include <stdint.h>

extern int abs(int n);
extern int pow(int n, short s);
extern uint32_t hex_pow(uint32_t n, short s);
extern uint8_t int_len(int n);
extern uint8_t hex_len(uint32_t n);

#endif
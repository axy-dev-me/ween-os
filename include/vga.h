#ifndef VGA_H
#define VGA_H

#include <stdint.h>

#define VGA_SIZE 4000
#define VGA_ADRESS 0xb8000

extern void print_char(char chr, int8_t color);
extern void print_string(char* str, int8_t color);
extern void print_int(int num, int8_t color);
extern void print_hex(uint32_t num, int8_t color);
extern void clean_screen(void);

#endif
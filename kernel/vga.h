#ifndef VGA_H
#define VGA_H

#include <stdint.h>

extern uint16_t *vga;
extern int16_t cursor;

void print_char(int8_t chr, int8_t color);
void print_string(int8_t* str, int8_t color);
void clean_screen(void);

#endif
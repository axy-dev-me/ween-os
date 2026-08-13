#include <stdint.h>
#include "vga.h"

uint16_t* vga = (uint16_t*)0xb8000;
int16_t cursor = 0;

void print_char(int8_t chr, int8_t color) {
    vga[cursor++] = chr + (color << 8);
}

void print_string(int8_t* str, int8_t color) {
    for (int16_t i = 0; str[i] != '\0';) print_char(str[i++], color);
}

void clean_screen(void) {
    for (int16_t i = 0; i != 4000;) vga[i++] = 0x720;
}
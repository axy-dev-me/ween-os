#include <stdint.h>
#include "vga.h"
#include "logic.h"

static uint16_t* vga = (uint16_t*) VGA_ADRESS;
static uint16_t cursor = 0;

static void reset_cursor(void) { cursor = 0; }

void print_char(char chr, int8_t color) {
    if (cursor < VGA_SIZE) {
        if (chr != '\n') vga[cursor++] = chr + (color << 8);
        else cursor = (cursor / 80 + 1) * 80;
    }
}

void print_string(char* str, int8_t color) {
    for (int16_t i = 0; str[i] != '\0'; i++) {
        print_char(str[i], color);
    }
}

void print_int(int num, int8_t color) {
    if (num == 0) { print_char('0', color); return; }
    if (num < 0) { print_char('-', color); num = -num; }

    for (short i = int_len(num); i != 0; i--) {
        uint8_t np = ((int) num / pow(10, i - 1)) % 10;
        print_char('0' + np, color);
    }
}

void print_hex(uint32_t num, int8_t color) {
    print_string("0x", color);

    if (num == 0) { print_char('0', color); return; }

    for (short i = hex_len(num); i != 0; i--) {
        uint8_t np = (num / hex_pow(16, i - 1)) % 16;
        
        if (np < 10) print_char('0' + np, color);
        else print_char('a' + np - 10, color);
    }
}

void clean_screen(void) {
    for (int16_t i = 0; i != VGA_SIZE; i++) {
        vga[i] = 0x720;
    }

    reset_cursor();
}
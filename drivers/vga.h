#ifndef VGA_H
#define VGA_H

#include "logic.h"
#include "types.h"
#include "math.h"
#include "hal.h"

static volatile uint16_t* video_memory = (volatile uint16_t*) 0xB8000;
static uint16_t cursor = 0;
static uint16_t max_cursor = 0;

__sil_void update_hardware_cursor() {
    outb(0x3D4, 14);
    outb(0x3D5, (uint8_t)((cursor >> 8) & 0xFF));
    
    outb(0x3D4, 15);
    outb(0x3D5, (uint8_t)(cursor & 0xFF));
}
__sil_void reset_cursor() { cursor = 0; max_cursor = 0; update_hardware_cursor(); }

__sil_void erase_last_simb() { cursor--; video_memory[cursor] = 0x0720; update_hardware_cursor(); }

__sil_void change_last_simb(char chr) { cursor--; video_memory[cursor] = chr; update_hardware_cursor(); }

__sil_void print_char(char chr, int color) {
    if (chr == '\n') {
        cursor = ((cursor / 80) + 1) * 80;
    } else if (chr == '\b' && cursor > max_cursor) {
        erase_last_simb();
    } else {
        video_memory[cursor] = chr | (color << 8);
        cursor++;
    } update_hardware_cursor();
}

__sil_void print_ro_char(char chr, int color) {
    print_char(chr, color);
    max_cursor = cursor;
}

__sil_void print_string(char* text, int color) {
    for (short i = 0; text[i] != '\0'; i++) {
        print_char(text[i], color);
    }
}

__sil_void print_ro_string(char* text, int color) {
    print_string(text, color);
    max_cursor = cursor;
}

__sil_void print_int(int num, int color) {
    if (num == 0) { print_char('0', color); return; }
    if (num < 0) print_char('-', color);
    
    for (uint8_t i = int_len(num); i != 1; i--) {
        print_char(((num / (pow(10, i - 1))) % 10) + '0', 0x0f);
    } print_char((num % 10) + '0', 0x0f);
}

__sil_void print_ro_int(int num, int color) {
    print_int(num, color);
    max_cursor = cursor;
}


__sil_void clear_screen(void) {
    reset_cursor();
    for (int i = 0; i < 4000; i++) video_memory[i] = (unsigned short)0x0720;
}

__sil_void print_time_unit(uint8_t val) {
    print_char((val / 10) + '0', 0x0f);
    print_char((val % 10) + '0', 0x0f);
}

#endif
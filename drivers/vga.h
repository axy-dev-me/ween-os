#ifndef VGA_H
#define VGA_H

#include "logic.h"

static volatile unsigned short* video_memory = (volatile unsigned short*) 0xB8000;
static unsigned short cursor = 0;
static unsigned short max_cursor = 0;

static inline void reset_cursor() {
    cursor = 0; max_cursor = 0;
}

static inline void erase_last_simb() {
    cursor--;
    video_memory[cursor] = 0x0720;
}

static inline void print_char(char chr, int color) {
    if (chr == '\n') {
        cursor = ((cursor / 80) + 1) * 80;
    } else if (chr == '\b' && cursor > max_cursor) {
        erase_last_simb();
    } else {
        video_memory[cursor] = chr | (color << 8);
        cursor++;
    }
}

static inline void print_ro_char(char chr, int color) {
    print_char(chr, color);
    max_cursor = cursor;
}

static inline void print_string(char* text, int color) {
    for (short i = 0; text[i] != '\0'; i++) {
        print_char(text[i], color);
    }
}

static inline void print_ro_string(char* text, int color) {
    print_string(text, color);
    max_cursor = cursor;
}

static inline void print_int(int num, int color) {
    if (num == 0) { 
        print_char('0', color); 
        return; 
    }
    if (num < 0) {
        print_char('-', color);
        num = -num;
    }

    int len = int_len(num);
    int target_pos = cursor + len - 1;

    while (num > 0) {
        video_memory[target_pos] = ((num % 10) + '0') | (color << 8);
        target_pos--;
        num /= 10;
    }

    cursor += len;
}

static inline void print_ro_int(int num, int color) {
    print_int(num, color);
    max_cursor = cursor;
}


static inline void clear_screen(void) {
    reset_cursor();
    for (int i = 0; i < 4000; i++) {
        video_memory[i] = (unsigned short)0x0720;
    }
}

#endif
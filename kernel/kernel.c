#include "hal.h"

volatile unsigned short* video_memory = (volatile unsigned short*) 0xB8000;
unsigned short cursor = 0;

int int_len(int num) {
    if (num == 0) return 1;
    if (num < 0) num = -num;
    short len = 0;
    while (num > 0) {
        len++;
        num /= 10;
    }
    return len;
}

void print_string(char* text, int color) {
    for (short i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n') { 
            cursor = ((cursor / 80) + 1) * 80;
        } else { 
            video_memory[cursor] = text[i] | (color << 8); 
            cursor++; 
        }
    }
}

void print_int(int num, int color) {
    if (num == 0) { 
        print_string("0", color); 
        return; 
    }
    if (num < 0) {
        print_string("-", color);
        num = -num;
    }

    int len = int_len(num);

    cursor += len;

    while (num > 0) {
        video_memory[cursor - 1] = ((num % 10) + '0') | (color << 8);
        
        cursor--;
        num /= 10;
    }

    cursor += len;
}

void clear_screen() {
    for (int i = 0; i < 4000; i++) {
        video_memory[i] = (unsigned short)0x0720;
    }
}

__attribute__((section(".text.entry")))
void kernel() {
    clear_screen();

    print_string("Hello, World!\nHello\n", 0x0f);
    print_int(2026, 0x0f);

    while(1) { __asm__("hlt"); }
}

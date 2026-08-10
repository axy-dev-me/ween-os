#ifndef VGA_H
#define VGA_H

static volatile unsigned short* video_memory = (volatile unsigned short*) 0xB8000;
static unsigned short cursor = 0;

static inline int int_len(int num) {
    if (num == 0) return 1;
    if (num < 0) num = -num;
    short len = 0;
    while (num > 0) {
        len++;
        num /= 10;
    }
    return len;
}

static inline void print_char(char chr, int color) {
    if (chr == '\n') {
        cursor = ((cursor / 80) + 1) * 80;
    } else {
        video_memory[cursor] = chr | (color << 8);
        cursor++;
    }
}

static inline void print_string(char* text, int color) {
    for (short i = 0; text[i] != '\0'; i++) {
        print_char(text[i], color);
    }
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


static inline void clear_screen(void) {
    for (int i = 0; i < 4000; i++) {
        video_memory[i] = (unsigned short)0x0000;
    }
}

#endif
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "hal.h"

static const char kbd_map[] = {
    0,  0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 
    '\b',                                                              /* 0x0E - Backspace */
    '\t',                                                              /* 0x0F - Tab */
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']',        
    '\n',                                                              /* 0x1C - Enter */
    0,                                                                 /* 0x1D - Left Ctrl */
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',       
    0,                                                                 /* 0x2A - Left Shift */
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',            
    0,                                                                 /* 0x36 - Right Shift */
    '*',                                                               
    0,                                                                 /* 0x38 - Left Alt */
    ' '
};


static inline char get_char_blocked() {
    while ((inb(0x64) & 1) == 0);

    uint8_t scancode = inb(0x60);

    if (scancode & 0x80) {
        return 0;
    }

    if (scancode < sizeof(kbd_map)) {
        return kbd_map[scancode];
    }

    return 0;
}

#endif

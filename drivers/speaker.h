#ifndef SPEAKER_H
#define SPEAKER_H

#include "hal.h"

static inline void play_sound(unsigned int frequency) {
    if (frequency == 0) return;

    unsigned int div = 1193182 / frequency;

    outb(0x43, 0xB6);
    outb(0x42, (unsigned char) (div & 0xFF));
    outb(0x42, (unsigned char) ((div >> 8) & 0xFF));

    unsigned char tmp = inb(0x61);
    if (tmp != (tmp | 3)) {
        outb(0x61, tmp | 3);
    }
}

static inline void nosound() {
    unsigned char tmp = inb(0x61) & 0xFC;
    outb(0x61, tmp);
}

static inline void beep(int hz, int duration) {
    play_sound(hz);

    for (volatile int i = 0; i < duration * 10000; i++); 
    
    nosound();
}

#endif

#ifndef SPEAKER_H
#define SPEAKER_H

#include "hal.h"
#include "types.h"

__sil_void play_sound(uint32_t frequency) {
    if (frequency == 0) return;

    uint32_t div = 1193182 / frequency;

    outb(0x43, 0xB6);
    outb(0x42, (uint8_t) (div & 0xFF));
    outb(0x42, (uint8_t) ((div >> 8) & 0xFF));

    uint8_t tmp = inb(0x61);
    if (tmp != (tmp | 3)) outb(0x61, tmp | 3);
}

__sil_void nosound() { outb(0x61, inb(0x61) & 0xFC); }

__sil_void beep(int hz, int duration) {
    play_sound(hz);

    for (volatile int i = 0; i < duration * 10000; i++); 
    
    nosound();
}

#endif

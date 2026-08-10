#ifndef POWER_H
#define POWER_H

#include "hal.h"

static inline void sys_reboot() {
    outb(0x64, 0xFE);

    __asm__ volatile("lidt %0" : : "m"((struct { unsigned short limit; unsigned int base; }){0, 0}));
    __asm__ volatile("int $3");
}

static inline void qemu_shutdown() {
    outw(0x604, 0x2000);
    outw(0xB004, 0x2000);
}

#endif

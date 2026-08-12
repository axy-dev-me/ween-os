#ifndef POWER_H
#define POWER_H

#include "hal.h"
#include "types.h"

__sil_void sys_reboot() {
    outb(0x64, 0xFE);

    __asm__ volatile("lidt %0" : : "m"((struct { unsigned short limit; unsigned int base; }){0, 0}));
    __asm__ volatile("int $3");
}

__sil_void qemu_shutdown() {
    outw(0x604, 0x2000);
    outw(0xB004, 0x2000);
}

#endif

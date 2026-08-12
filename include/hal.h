#ifndef HAL_H
#define HAL_H

#include "types.h"

__sil_void __udivdi3() { while(1) { __asm__("hlt"); } }
__sil_void __umoddi3() { while(1) { __asm__("hlt"); } }
__sil_void __divdi3()  { while(1) { __asm__("hlt"); } }
__sil_void __moddi3()  { while(1) { __asm__("hlt"); } }

__sil_void outb(uint16_t port, uint8_t data) { __asm__ volatile("outb %0, %1" : : "a"(data), "Nd"(port)); }
__sil_void outw(uint16_t port, uint16_t data) { __asm__ volatile("outw %0, %1" : : "a"(data), "Nd"(port)); }

__sil_uint8_t inb(uint16_t port) {
    uint8_t result;
    __asm__ volatile("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

#endif

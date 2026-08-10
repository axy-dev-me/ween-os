#ifndef HAL_H
#define HAL_H

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;

void __udivdi3() { while(1) { __asm__("hlt"); } }
void __umoddi3() { while(1) { __asm__("hlt"); } }
void __divdi3()  { while(1) { __asm__("hlt"); } }
void __moddi3()  { while(1) { __asm__("hlt"); } }

static inline void outb(unsigned short port, unsigned char data) {
    __asm__ volatile("outb %0, %1" : : "a"(data), "Nd"(port));
}

static inline void outw(unsigned short port, unsigned short data) {
    __asm__ volatile("outw %0, %1" : : "a"(data), "Nd"(port));
}


static inline unsigned char inb(unsigned short port) {
    unsigned char result;
    __asm__ volatile("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

#endif

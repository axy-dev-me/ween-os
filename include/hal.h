#ifndef HAL_H
#define HAL_H

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;

void __udivdi3() { while(1) { __asm__("hlt"); } }
void __umoddi3() { while(1) { __asm__("hlt"); } }
void __divdi3()  { while(1) { __asm__("hlt"); } }
void __moddi3()  { while(1) { __asm__("hlt"); } }

#endif

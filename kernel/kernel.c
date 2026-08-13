#include <stdint.h>

__attribute__((section(".text.entry")))
void kmain() {
    int16_t* vga = (int16_t*)0xb8000;
    vga[0] = 'K' + (0x0f << 8);
    while(1) __asm__("hlt");
}
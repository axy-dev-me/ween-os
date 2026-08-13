#include <stdint.h>

#include "vga.h"

__attribute__((section(".text.entry")))
void kmain() {
    clean_screen();
    print_string("Hello, World!", 0x0f);
    while(1) __asm__("hlt");
}
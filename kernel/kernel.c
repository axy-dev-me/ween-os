#include <stdint.h>

#include "vga.h"

__attribute__((section(".text.entry")))
void kmain() {
    clean_screen();
    print_string("Hello, World!\n", 0x0f);
    print_hex(0xffffffff, 0x0c);
    print_char('\n', 0x0f);
    print_int(12345, 0x0b);
    while(1) __asm__("hlt");
}
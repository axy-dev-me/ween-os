#include "hal.h"
#include "vga.h"

__attribute__((section(".text.entry")))
void kernel() {
    clear_screen();

    print_string("Hello, World!\nHello\n", 0x0f);
    print_int(2026, 0x0f);

    while(1) { __asm__("hlt"); }
}

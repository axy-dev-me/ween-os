#include "hal.h"
#include "vga.h"
#include "speaker.h"

__attribute__((section(".text.entry")))
void kernel() {
    clear_screen();

    print_string("Hello, World!\nHello\n", 0x0f);
    print_int(2026, 0x0f);

    beep(1000, 1000);
    beep(2000, 1000);
    beep(1500, 1000);

    while(1) { __asm__("hlt"); }
}

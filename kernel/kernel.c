#include "shell.h"

__attribute__((section(".text.entry")))
void kernel() {
    rtc_time_t time;

    clear_screen();

    print_string("Welcome to Ween-OS!\nWrite \"help\" to view all available commands\n\n", 0x0f);
    print_ro_string("[root@weenos]> ", 0x0f);

    beep(1000, 1000);
    beep(2000, 1000);
    beep(1500, 1000);

    shell_loop(time);
}

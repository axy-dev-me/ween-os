#ifndef SHELL_H
#define SHELL_H

#include "hal.h"
#include "vga.h"
#include "speaker.h"
#include "power.h"
#include "keyboard.h"
#include "time.h"
#include "logic.h"

static inline void shell_loop(rtc_time_t time) {
    char cmd[80];
    short cmd_len = 0;

    while(1) {
        char letter = get_char_blocked();
        
        if (letter != 0 && letter != '\n' && letter != '\b') {
            print_char(letter, 0x0F);
            cmd[cmd_len] = letter; cmd_len++;
        } 
        else if (letter == '\b' && cmd_len > 0) {
            cmd_len--; erase_last_simb();
        } 
        else if (letter == '\n') {
            cmd[cmd_len] = '\0';
            print_char('\n', 0x0F);

            if (str_equals(cmd, "cls")) clear_screen();
            else if (str_equals(cmd, "reboot")) sys_reboot();
            else if (str_equals(cmd, "shutdown")) qemu_shutdown();
            else if (str_equals(cmd, "help")) {
                print_string("\ncls - clear screen\n", 0x0f);
                print_string("\nreboot - reboot system\n", 0x0f);
                print_string("\nshutdown - shutdown system\n", 0x0f);
                print_string("\ntime - show system time\n", 0x0f);
                print_char('\n', 0x0f);
            }
            else if (str_equals(cmd, "time")) {
                read_rtc(&time);
                print_int(time.hour, 0x0f); print_char(':', 0x0f);
                print_int(time.minute, 0x0f); print_char(':', 0x0f);
                print_int(time.second, 0x0f); print_char('\n', 0x0f);
            }
            else { print_string("Unknown command!\n", 0x0c); }

            print_ro_string("[root@weenos]> ", 0x0f);
            cmd_len = 0;
        }
    }
}

#endif
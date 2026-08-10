#include "hal.h"
#include "vga.h"
#include "speaker.h"
#include "power.h"
#include "keyboard.h"

static inline int str_equals(char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) return 0; i++;
    }
    return 1;
}

__attribute__((section(".text.entry")))
void kernel() {
    clear_screen();

    print_ro_string("Welcome to Ween-OS!\nWrite \"help\" to view all available commands\n\n", 0x0f);
    print_ro_string("[root@weenos]> ", 0x0f);

    beep(1000, 1000);
    beep(2000, 1000);
    beep(1500, 1000);

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
                print_string("\ncls - clear screen\n\nreboot - reboot system\n\nshutdown - shutdown system\n\n", 0x0f);
            }
            else { print_string("Unknown command!\n", 0x0c); }

            print_ro_string("[root@weenos]> ", 0x0f);
            cmd_len = 0;
        }
    }
}

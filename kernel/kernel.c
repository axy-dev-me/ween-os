volatile unsigned short* video_memory = (volatile unsigned short*) 0xB8000;
unsigned short cursor = 0;

void print_string(char* text, int color) {
    for (short i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n') { 
            cursor = ((cursor / 80) + 1) * 80;
        } else { 
            video_memory[cursor] = text[i] | (color << 8); 
            cursor++; 
        }
    }
}

void clear_screen() {
    for (int i = 0; i < 4000; i++) {
        video_memory[i] = (unsigned short)0x0720;
    }
}

__attribute__((section(".text.entry")))
void kernel() {
    clear_screen();

    print_string("Hello, World!\nHello", 0x0f);

    while(1) { __asm__("hlt"); }
}

volatile unsigned short* video_memory = (volatile unsigned short*) 0xB8000;
unsigned short cursor = 0;

void print_string(char* text, int color) {
    for (short i = 0; text[i] != '\0'; i++) {
        video_memory[cursor] = text[i] | (color << 8);
        cursor++;
    }
}

__attribute__((section(".text.entry")))
void kernel() {
    unsigned short blank = 0x0720; 
    for (int i = 0; i < 4000; i++) {
        video_memory[i] = blank;
    }

    print_string("Hello, World!", 0x0f);

    while(1) { __asm__("hlt"); }
}

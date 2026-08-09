__attribute__((section(".text.entry")))
void kernel() {
    volatile unsigned short* video_memory = (volatile unsigned short*) 0xB8000;

    unsigned short blank = 0x0720; 
    for (int i = 0; i < 4000; i++) {
        video_memory[i] = blank;
    }

    video_memory[0] = 'H' | (0x0F << 8);
    video_memory[1] = 'e' | (0x0F << 8);
    video_memory[2] = 'l' | (0x0F << 8);
    video_memory[3] = 'l' | (0x0F << 8);
    video_memory[4] = 'o' | (0x0F << 8);

    while(1) { __asm__("hlt"); }
}

# My Own Operating System Kernel

A minimalist operating system kernel written in C for the x86 architecture.

## What's already done:
- Custom bootloader that handles the initial boot sector setup
- Global Descriptor Table (GDT) initialization and transition to 32-bit Protected Mode
- Kernel entry point and execution handoff (`kernel`)
- Direct VGA video memory access (`0xB8000`) in 80x50 mode
- Full screen clearance and welcome text "Hello" output

## How to run:
To build the project and launch it in the QEMU emulator, simply run:
```bash
make run
```

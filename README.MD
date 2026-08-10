# 🚀 WeenOS

A simple, lightweight 32-bit x86 hobby operating system kernel written in C and Assembly. This project is built for educational purposes to explore low-level software development, VGA video memory management, bare-metal programming, and hardware interfacing.

## ✨ Features
* 🖥️ **Direct VGA Text Mode Output:** Writes characters directly to `0xB8000` (80x25 grid).
* 🎨 **Color Attributes:** Full support for custom text and background colors via 8-bit attribute bytes.
* 🔢 **Integer Rendering:** A robust `print_int` function with automated length calculation.
* 🧹 **Screen Clearing:** Dedicated `clear_screen` utility to reset the display matrix.
* 🛑 **CPU Halting:** Safely stops the processor using a loop with the `hlt` assembly instruction.

## 🛠️ Tech Stack
* **Language:** C (C99/C11 standards), GCC.
* **Architecture:** x86 (32-bit Protected Mode).
* **Emulation:** QEMU / VirtualBox.

## 🚀 Getting Started

### 📋 Prerequisites
To build and run this kernel, you will need:
* `gcc` (with x86 32-bit compilation support, e.g., `gcc-multilib`)
* `nasm`
* `make`
* `qemu-system-i386`

### 🔧 Installation & Execution
1. Clone the repository:
   ```bash
   git clone https://github.com/axy-dev-me/ween-os/main.git
   cd ween-os
   ```
2. Compile and launch the OS inside QEMU:
   ```bash
   make run
   ```
*(Note: If your Makefile uses a different command, replace `make run` with your specific setup).*

## 🗺️ Roadmap
- [ ] Implement text scrolling (prevent out-of-bounds cursor on line 26+).
- [ ] Add control characters parsing (e.g., `\t` tabs, `\r` carriage returns).
- [ ] Develop a basic Keyboard Driver (interrupt-based typing).
- [ ] Configure the Interrupt Descriptor Table (IDT).

## 📄 License
This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for more details.

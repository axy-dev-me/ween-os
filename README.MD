# 🚀 WeenOS

A simple, lightweight 32-bit x86 hobby operating system kernel written in C and Assembly.

## Tech Stack
* **Language:** C (C99/C11 standards), GCC.
* **Architecture:** x86 (32-bit Protected Mode).
* **Emulation:** QEMU.

## Getting Started

### Prerequisites
To build and run this kernel, you will need:
* `gcc` (with x86 32-bit compilation support, e.g., `gcc-multilib`)
* `nasm`
* `make`
* `qemu-system-i386`

### Installation & Execution
1. Clone the repository:
   ```bash
   git clone https://github.com/axy-dev-me/ween-os/main.git
   cd ween-os
   ```
2. Compile and launch the OS inside QEMU:
   ```bash
   make run
   ```

## 📄 License
This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for more details.

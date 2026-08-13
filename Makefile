ARCH = i386
CFLAGS = -m32 -fno-pie -fno-pic -nostdlib
LDFLAGS = -m elf_i386 -T linker.ld --oformat binary

run:
	mkdir -p tmp

	nasm -fbin boot/boot.s -o tmp/boot.bin

	gcc $(CFLAGS) -c kernel/kernel.c -o tmp/kernel.o
	ld $(LDFLAGS) tmp/kernel.o -o tmp/kernel.bin

	cat tmp/boot.bin tmp/kernel.bin > tmp/os.bin

	qemu-system-$(ARCH) tmp/os.bin

	rm -rf tmp
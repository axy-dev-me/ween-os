ARCH = i386
CFLAGS = -m32 -fno-pie -fno-pic -nostdlib -Ikernel
LDFLAGS = -m elf_i386 -T linker.ld --oformat binary

run:
	mkdir -p tmp

	nasm -fbin boot/boot.s -o tmp/boot.bin

	gcc $(CFLAGS) -c kernel/*.c
	mv *.o tmp/
	ld $(LDFLAGS) tmp/*.o -o tmp/kernel.bin

	cat tmp/boot.bin tmp/kernel.bin > tmp/os.img

	qemu-system-$(ARCH) tmp/os.img

	rm -rf tmp

build:
	mkdir -p tmp build

	nasm -fbin boot/boot.s -o tmp/boot.bin

	gcc $(CFLAGS) -c kernel/*.c
	mv *.o tmp/
	ld $(LDFLAGS) tmp/*.o -o tmp/kernel.bin

	cat tmp/boot.bin tmp/kernel.bin > build/os.img

	rm -rf tmp
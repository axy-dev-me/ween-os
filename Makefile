arch = i386

run:
	mkdir -p tmp
	nasm -fbin boot/boot.s -o tmp/boot.bin
	gcc -m32 -fno-pie -ffreestanding -Iinclude -nostdlib -c kernel/kernel.c -o tmp/kernel.o
	ld -m elf_i386 -T linker.ld --oformat binary tmp/kernel.o -o tmp/kernel.bin
	cat tmp/boot.bin tmp/kernel.bin > tmp/os.bin
	qemu-system-$(arch) tmp/os.bin
	rm -rf tmp

build:
	mkdir -p tmp build
	nasm -fbin boot/boot.s -o tmp/boot.bin
	gcc -m32 -fno-pie -ffreestanding -Iinclude -nostdlib -c kernel/kernel.c -o tmp/kernel.o
	ld -m elf_i386 -T linker.ld --oformat binary tmp/kernel.o -o tmp/kernel.bin
	cat tmp/boot.bin tmp/kernel.bin > build/os.bin
	rm -rf tmp

clean:
	rm -rf build
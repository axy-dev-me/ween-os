arch = i386

run:
	mkdir -p tmp

	nasm -fbin boot/boot.s -o tmp/boot.bin

	qemu-system-i386 tmp/boot.bin

	rm -rf tmp
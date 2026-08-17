ARCH = i386
CFLAGS = -m32 -fno-pie -fno-pic -fno-builtin -nostdlib -Iinclude
LDFLAGS = -m elf_i386 -T linker.ld --oformat binary

run:
	mkdir -p tmp

	nasm -fbin boot/boot.s -o tmp/boot.bin

	gcc $(CFLAGS) -c kernel/*.c
	mv *.o tmp/
	ld $(LDFLAGS) tmp/*.o -o tmp/kernel.bin

	cat tmp/boot.bin tmp/kernel.bin > tmp/os.img
	dd if=/dev/zero of=tmp/os.img bs=512 count=0 seek=64

	qemu-system-$(ARCH) tmp/os.img

	rm -rf tmp

build:
	mkdir -p tmp build

	nasm -fbin boot/boot.s -o tmp/boot.bin

	gcc $(CFLAGS) -c kernel/*.c
	mv *.o tmp/
	ld $(LDFLAGS) tmp/*.o -o tmp/kernel.bin

	cat tmp/boot.bin tmp/kernel.bin > tmp/os.img
	dd if=/dev/zero of=tmp/os.img bs=512 count=0 seek=64
	mv tmp/os.img build/

	rm -rf tmp

clean:
	rm -rf build
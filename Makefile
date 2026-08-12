arch = i386

run:
	mkdir -p tmp

	nasm -fbin boot/boot.s -o tmp/boot.bin

	gcc -m32 -fno-pie -ffreestanding -fno-stack-protector -Iinclude -Idrivers -Ikernel -nostdlib -c kernel/kernel.c -o tmp/kernel.o
	ld -m elf_i386 -T linker.ld --oformat binary tmp/kernel.o -o tmp/kernel.bin

	cat tmp/boot.bin tmp/kernel.bin > tmp/os_raw.bin

	dd if=/dev/zero of=tmp/os.bin bs=512 count=32 2>/dev/null
	dd if=tmp/os_raw.bin of=tmp/os.bin conv=notrunc 2>/dev/null

	qemu-system-$(arch) tmp/os.bin -audiodev pa,id=snd0 -machine pcspk-audiodev=snd0

	rm -rf tmp

build:
	mkdir -p tmp build

	nasm -fbin boot/boot.s -o tmp/boot.bin

	gcc -m32 -fno-pie -ffreestanding -fno-stack-protector -Iinclude -Idrivers -Ikernel -nostdlib -c kernel/kernel.c -o tmp/kernel.o
	ld -m elf_i386 -T linker.ld --oformat binary tmp/kernel.o -o tmp/kernel.bin

	cat tmp/boot.bin tmp/kernel.bin > tmp/os_raw.bin

	dd if=/dev/zero of=build/os.bin bs=512 count=32 2>/dev/null
	dd if=tmp/os_raw.bin of=build/os.bin conv=notrunc 2>/dev/null

	rm -rf tmp

clean:
	rm -rf build
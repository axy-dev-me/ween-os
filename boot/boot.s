org 0x7c00
bits 16

start:
    mov ax, 0x0003
    int 0x10



    mov si, diskread
    call print16

    mov ah, 0x02
    mov al, 3
    mov ch, 0
    mov cl, 2
    mov dh, 0
    mov dl, 0x80
    mov bx, 0x1000
    mov es, bx
    mov bx, 0x0000
    int 0x13

    jc disk_error

    mov si, done
    call print16

    mov si, loadkern
    call print16



    cli

    lgdt [gdt_pointer]

    mov eax, cr0
    or eax, 1
    mov cr0, eax

    jmp 0x08:dword init_pm



disk_error:
    mov si, diskerr
    call print16
    cli
    hlt
    jmp $



bits 32
init_pm:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    mov esp, 0x90000
    mov ebp, esp

    jmp 0x10000



diskread db 'Reading Disk... ', 0
loadkern db 'Loading kernel... ', 0
done db 'Done! ', 0x0d, 0x0a, 0
diskerr db 0x0d, 0x0a, 'Disk Error!', 0

%include "boot/libs/print16.s"
%include "boot/libs/gdt.s"

times 510-($-$$) db 0
dw 0xaa55
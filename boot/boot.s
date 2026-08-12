bits 16
org 0x7c00
jmp 0x0000:_start

_start:
    mov [boot_drive], dl

    xor ax, ax
    mov ds, ax
    mov es, ax
    
    mov cl, 0x02
    mov bx, 0x8000
    call load_disk

    mov ah, 0x0e
    mov al, [0x8000]
    int 0x10

    hlt
    jmp $

boot_drive: db 0

%include "boot/disk.s"

times 510-($-$$) db 0
dw 0xaa55
db 's'
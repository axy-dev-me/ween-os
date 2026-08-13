bits 16
org 0x7c00
jmp 0x0000:_start

_start:
    mov [boot_drive], dl

    xor ax, ax
    mov ds, ax
    mov es, ax

    call load_disk
    call switch_to_pm

    hlt
    jmp $

boot_drive: db 0

%include "boot/disk.s"
%include "boot/gdt.s"
%include "boot/switch.s"

times 510-($-$$) db 0
dw 0xaa55

; kernel:
; bits 32
;     mov byte [0xb8000], 'K'
;     mov byte [0xb8001], 0x0a
;     hlt
;     jmp $

; times 512-($-kernel) db 0
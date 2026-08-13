bits 16
load_disk:
    pusha
    
    mov ah, 0x42
    mov dl, [boot_drive]
    mov si, dap

    int 0x13 

    jc .error

    popa
    ret

.error:
    mov ah, 0x0e
    mov al, 'e'
    int 0x10
    
    hlt
    jmp $

sectors_read: db 1

align 4
dap:
    db 0x10
    db 0x00
    dw 1                  ; sectors to read

    ; bx and es
    dw 0x0
    dw 0x0800
    
    dq 1
print16:
    pusha
    cld
    mov ah, 0x0e
    mov bh, 0
    mov bl, 0x07

.loop:
    lodsb
    test al, al
    jz .done
    int 0x10
    jmp .loop

.done:
    popa
    ret
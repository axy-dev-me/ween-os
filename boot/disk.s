load_disk:
    pusha
    
    mov ah, 0x02
    mov al, [sectors_read]
    mov ch, 0x00
    mov dh, 0x00
    mov dl, [boot_drive]

    int 0x13

    jc .error

    cmp al, [sectors_read]
    jne .error

    popa
    ret

.error:
    mov ah, 0x0e
    mov al, 'e'
    int 0x10
    hlt
    jmp $

sectors_read: db 1
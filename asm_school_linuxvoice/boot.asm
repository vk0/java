	BITS 16

	mov ax, 07C0h	; Where we're loaded
	mov ds, ax	; Data segment

	mov ax, 9000h	; Set up stack
	mov ss, ax
	mov sp, 0FFFFh	; Grows downwards!

	mov ah, 0	; Set video mode routine
	mov al, 0Dh	; 320x200x16 colours
	int 10h		; Call BIOS

loop:
	mov si, text_string
	call print_string
	inc bl		; Change colour
	jmp loop

	text_string db 'Bare metal rules! ', 0

print_string:
	mov ah, 0Eh	; Print character routine
.repeat:
	lodsb
	cmp al, 0
	je .done
	int 10h		; Call BIOS
	jmp .repeat
.done:
	ret

	times 510-($-$$) db 0
	dw 0AA55h	; Boot signature

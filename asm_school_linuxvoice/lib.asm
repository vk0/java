; ---------------------------------------------------------------------------
; Library of subroutines for x86 Linux assembly
; From Linux Voice issue 13 -- v1.0. Public domain!
; ---------------------------------------------------------------------------


section .text

; Print text string
; In: ecx = location of zero-terminated string
; Out: Nothing

lib_print_string:
	pusha			; Save all regs

	mov eax, ecx		; Work with eax, and leave ecx untouched for now
	mov edx, 0		; Character counter (string length)
.loop:
	cmp byte [eax], 0 	; Is byte in current position in string zero?
	je .done		; Jump ahead if so
	inc edx			; Increment counter
	inc eax			; And string loc
	jmp .loop		; And carry on the loop

.done:
	mov eax, 4		; sys_write
	mov ebx, 1		; stdout
	int 80h			; Call kernel (ecx was set earlier)

	popa			; Restore all regs
	ret			; Back to caller


; ---------------------------------------------------------------------------

section .text

; Display contents of eax, ebx, ecx, edx, esi, edi
; In: Above mentioned registers
; Out: Nothing

lib_print_registers:
	pusha

	push ecx		; Save this for later, as ecx is used by lib_print_string

	mov ecx, eax_string
	call lib_print_string
	call lib_int_to_string
	call lib_print_string 

	mov ecx, ebx_string
	call lib_print_string
	mov eax, ebx
	call lib_int_to_string
	call lib_print_string 

	mov ecx, ecx_string
	call lib_print_string
	pop eax			; Get the ecx back that we stored
	call lib_int_to_string
	call lib_print_string 

	mov ecx, edx_string
	call lib_print_string
	mov eax, edx
	call lib_int_to_string
	call lib_print_string 

	mov ecx, esi_string
	call lib_print_string
	mov eax, esi
	call lib_int_to_string
	call lib_print_string 

	mov ecx, edi_string
	call lib_print_string
	mov eax, edi
	call lib_int_to_string
	call lib_print_string

	mov ecx, newline_string
	call lib_print_string

	popa
	ret

section .data
	eax_string db "EAX: ", 0
	ebx_string db 10, "EBX: ", 0
	ecx_string db 10, "ECX: ", 0
	edx_string db 10, "EDX: ", 0
	esi_string db 10, "ESI: ", 0
	edi_string db 10, "EDI: ", 0
	newline_string db 10, 0


; ---------------------------------------------------------------------------

section .text

; Convert unsigned integer to string
; In: eax = unsigned integer
; Out: ecx = string location

lib_int_to_string:
	pusha
	mov esi, int_to_string_store
	add esi, 9			; Work from right-to-left in string
	mov byte [esi], 0		; Zero-terminate string
	dec esi

	mov ebx, 10
.next_digit:
	mov edx, 0			; Clear remainder
	div ebx				; Divide number by 10
	add dl, '0'			; Convert remainder to ASCII
	dec esi
	mov [esi], dl			; Store character
	cmp eax, 0			; Any more to go?
	jnz .next_digit
	mov [int_to_string_tmp], esi
	popa				; Restore all registers...
	mov ecx, [int_to_string_tmp]	; ...but get string location back for calling code
	ret

section .data
	int_to_string_tmp dd 0
	int_to_string_store times 10 db 0


; ---------------------------------------------------------------------------


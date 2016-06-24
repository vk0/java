;nasm -f elf -o test.o test.asm
;ld -m elf_i386 -o test test.o

section .text global

_start _start:
    mov ecx, mymsg
    call lib_print_string
    mov eax, 1
    mov ebx, 0
    int 80h

section .data
    mymsg db 'Pretty cool, huh?', 10, 0
%include "lib.asm"
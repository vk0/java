;nasm -f elf -o myfirst.o myfirst.asm
;ld -m elf_i386 -o myfirst myfirst.o
;objdump -d -M intel myfirst

section          .text
global           _start

_start:
    mov ecx, message
    mov edx, length
    mov ebx, 1
    mov eax, 4
    int 0x80

    mov eax, 1
    int 0x80

section .data
    message  db  'Assembly rules!', 10
    length   equ $ - message
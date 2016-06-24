#!/bin/sh
apt-get install -y qemu dosbox mtools

nasm -f bin -o boot.bin boot.asm
mkdosfs -C floppy.img 1440
dd conv=notrunc if=boot.bin of=floppy.img
nasm -f bin -o mykernel.bin mykernel.asm
mcopy -i floppy.img mykernel.bin ::/
nasm -f bin -o test.bin test.asm
mcopy -i floppy.img test.bin ::/
qemu-system-i386 -fda floppy.img
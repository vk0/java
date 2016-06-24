#!/bin/sh
apt-get install -y qemu dosbox

mkdosfs -C floppy.img 1440
nasm -f bin -o boot.bin boot.asm
dd if=boot.bin of=floppy.img conv=notrunc
dosbox floppy.img
qemu-system-i386 floppy.img
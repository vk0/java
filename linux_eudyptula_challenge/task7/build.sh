#!/bin/sh
# https://www.kernel.org/doc/man-pages/linux-next.html
git clone https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git
cd linux
git remote add linux-next https://git.kernel.org/pub/scm/linux/kernel/git/next/linux-next.git
git fetch linux-next
#make defconfig
cp /boot/config-`uname -r` ./.config
make -j 8
make modules_install
cp -v arch/x86_64/boot/bzImage /boot/vmlinuz-linux-next
mkinitcpio -k linux-next -c /etc/mkinitcpio.conf -g /boot/initramfs-linux-next.img
grub-mkconfig
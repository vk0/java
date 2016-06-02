#!/bin/sh
wget https://cdn.kernel.org/pub/linux/kernel/v4.x/linux-4.6.1.tar.xz
tar xvf linux-4.6.1.tar.xz
cd linux-4.6.1
# or git clone https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/
#make defconfig
cp /boot/config-`uname -r` ./.config
# vi .config and change CONFIG_LOCALVERSION_AUTO and diff -Naur
patch .config < config_localversion.patch
make -j 8
make modules_install
cp -v arch/x86_64/boot/bzImage /boot/vmlinuz-4.6.1-kernel
mkinitcpio -k 4.6.1-kernel -c /etc/mkinitcpio.conf -g /boot/initramfs-4.6.1-kernel.img
grub-mkconfig
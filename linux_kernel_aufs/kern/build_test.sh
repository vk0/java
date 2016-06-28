#!/bin/sh
make
sudo insmod ./aufs.ko
lsmod | grep aufs
touch image
mkdir dir
sudo mount -o loop -t aufs ./image ./dir
sudo umount ./dir
sudo rmmod aufs
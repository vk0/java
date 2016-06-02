#!/bin/sh

# Build module for current kernel
make

# Show module info
modinfo ./hello.ko

# Install module
sudo insmod ./hello.ko
dmesg | tail -1

# [532100.715394] Load hello.ko module
# Check module
lsmod |grep hello
# hello                  16384  0

# Uninstall module
sudo rmmod hello
dmesg | tail -1
# [532167.151294] Remove hello.ko module
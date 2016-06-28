#!/bin/sh
sudo apt-get install -y gcc build-essential
sudo apt-get install -y linux-headers-`uname -r`
make
sudo insmod ./aufs.ko
lsmod | grep aufs
sudo rmmod aufs
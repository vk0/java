#!/usr/bin/env python2

import subprocess

def uname_func():
    uname = "uname"
    uname_arg = "-a"
    subprocess.call([uname, uname_arg])

def disk_func():
    diskspace = "df"
    diskspace_arg = "-h"
    subprocess.call([diskspace, diskspace_arg])

def main():
    uname_func()
    disk_func()
if __name__ == "__main__":
    ain()


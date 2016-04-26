#!/usr/bin/env python
# -*- coding: utf-8 -*-
# unix cat cmd analog

from __future__ import print_function
import sys, os.path
for arg in sys.argv[1:]:
    if not os.path.isfile(arg):
        print("no such file", arg, file=sys.stderr)
    else:
        with open(arg) as file:
            for line in file:
                print(line, end="")

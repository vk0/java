#!/usr/bin/env python2
import sys

num_arg = len(sys.argv) - 1

if num_arg == 0:
    sys.stderr.write("No arg")
else:
    print(sys.argv, "You typed in", num_arg, "arguments")
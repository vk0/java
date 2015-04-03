#!/usr/bin/env python2
import optparse
import os

def main():
    p = optparse.OptionParser(description="python ls command", prog="pyls", version="0.1a", usage="%prog [directory]")
    options, arguments = p.parse_args()
    if len(arguments) == 1:
        path = arguments[0]
        for filename in os.listdir(path):
            print(filename)
    else:
        p.print_help()
if __name__ == '__main__':
    main()
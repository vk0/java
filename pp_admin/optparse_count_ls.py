#!/usr/bin/env python2
import optparse
import os

def main():
    p = optparse.OptionParser(description="python ls command", prog="pyls", version="0.1a", usage="%prog [directory]")
    p.add_option("-v", action="count", dest="verbose")
    options, arguments = p.parse_args()
    if len(arguments) == 1:
        if options.verbose:
            print("Verbose Mode Enable at Level: %s" % options.verbose)
        path = arguments[0]
        for filename in os.listdir(path):
            if options.verbose == 1:
                print "Filename: %s" % filename
            elif options.verbose == 2:
                fullpath = os.path.join(path, filename)
                print("Filename: %s | Byte Size: %s" % (filename,os.path.getsize(fullpath)))
            else:
                print filename
    else:
        p.print_help()

if __name__ == '__main__':
    main()

#!/usr/bin/env python
# -*- coding: utf-8 -*-
# unix echo cmd analog
from __future__ import print_function
import argparse, sys
parser = argparse.ArgumentParser(description="from stdin to stdout")
parser.add_argument('echo', help="some data")
parser.add_argument("--stderr", help="from stderr to stdin", action="store_true")
args = parser.parse_args()
if args.stderr:
    print(args.echo, file=sys.stderr)
else:
    print(args.echo)
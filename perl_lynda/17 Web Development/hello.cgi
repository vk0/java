#!/usr/bin/perl
# hello.cgi by Bill Weinman <http://bw.org/contact/>
# Copyright (c) 2010 The BearHeart Group, LLC
#
use strict;
use warnings;

print "Content-type: text/html\n\n";

print <<PAGE;
<html>
<head>
    <title> Hello, World! </title>
    <style>
        body { background-color: white }
        .hello {
            font-family: trebuchet ms, sans-serif;
            font-size: 24pt;
            margin-top: 100px;
            text-align: center;
        }
    </style>
</head>
<body>
    <p class="hello"> Hello, World! </p>
</body>
</html>
PAGE


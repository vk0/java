import sys

dict = {'a' : 'c',
        'b' : 'd',
	'c' : 'e',
	'd' : 'f',
	'e' : 'g',
	'f' : 'h',
	'g' : 'i',
	'h' : 'j',
	'i' : 'k',
	'j' : 'l',
	'k' : 'm',
	'l' : 'n',
	'm' : 'o',
	'n' : 'p',
	'o' : 'q',
	'p' : 'r',
	'q' : 's',
	'r' : 't',
	's' : 'u',
	't' : 'v',
	'u' : 'w',
	'v' : 'x',
	'w' : 'y',
	'x' : 'z',
	'y' : 'a',
	'z' : 'b',
	' ' : ' ',
	'.' : '.',
	'(' : '(',
	')' : ')',
	'\'': '\''}

st = "g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj."

for i in range(len(st)):
	sys.stdout.write('%c' % dict[st[i]]);

print

st = "map"
for i in range(len(st)):
	sys.stdout.write('%c' % dict[st[i]]);

print

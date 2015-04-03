import os

parm = 0
while True:
    parm += 1
    pid = os.fork()
    if pid == 0:
        os.execlp('python','python','child.py',str(parm))
        assert False, 'error staring program'
    else:
        print('Child is', pid)
        if input() == 'q': break
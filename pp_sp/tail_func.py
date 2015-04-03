import time

def tail(f):
    f.seek(0,2)
    while True:
        line = f.readline()
        if not line:
            time.sleep(0.1)
            continue
        yield line

if __name__ == '__main__':
    import sys
    filename = sys.argv[1]
    tail(open(filename))
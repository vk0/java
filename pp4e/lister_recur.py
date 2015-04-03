import sys, os

def mylister(currdir):
    print('[' + currdir + ']')
    for file in os.listdir(currdir):
        path = os.path.join(currdir, file)
        if not os.path.isdir(path):
            print(path)
        else:
            mylister(path)

if __name__ == '__main__':
    mylister(sys.argv[1])
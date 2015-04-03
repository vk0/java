import sys, os
matches = []

def lister(dir, module):
    for (dirname, dirshere, fileshere) in os.walk(dir):
        for filename in fileshere:
            if filename.endswith('.py'):
                pathname = os.path.join(dirname,filename)
                if 'os' in open(pathname).read():
                    matches.append(pathname)
for name in matches:
    print(name)

if __name__ == '__main__':
    lister(sys.argv[1], sys.argv[2])
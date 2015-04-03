import os
path = '/tmp'

def enumeratepaths(path=path):
    path_collection = []
    for dirpath, dirnames, filenames in os.walk(path):
        for file in filenames:
            fullpath = os.path.join(dirpath, file)
            path_collection.append(fullpath)
    return path_collection

def enumeratefiles(path=path):
    file_collection = []
    for dirpath, dirnames, filenames in os.walk(path):
        for file in filenames:
            file_collection.append(file)
    return file_collection

def enumeratedir(path=path):
    dir_collection = []
    for dirpath, dirnames, filenames in os.walk(path):
        for dir in dirnames:
            dir_collection.append(dir)
    return dir_collection

if __name__ == '__main__':
    print("\nRecursive listing of all paths in a dir:")
    for path in enumeratepaths():
        print path

    print("\nRecursive listing of all files in a dir:")
    for file in enumeratefiles():
        print file

    print("\nRecursive listing of all dirs in a dir:")
    for dir in enumeratedir():
        print dir

import os
c = "D:\\Python"

for (path, dirs, files) in os.walk(c):
    for File in files:
        p = os.path.join(path, File)
        print os.path.relpath(p, c)
    #if "Application Data" in dirs:
        #dirs.remove("Application Data")

        #print "FOUND"
    #print path

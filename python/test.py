#open file for read
#fd = open(u"C:\\test.txt", "wt+")
fd2 = open('C:\\test2.txt', 'w')
#with open("C:\\test2.txt", "wt+") as fd2:
#one = fd.readline() #read line
#one2 = fd.read(12) #read bytes
fd2.write("HUI")
fd2.close



#print one2
#print fd2

#print fd
#for line in fd:
    #print line, #do not show newline at the end
 #   L = line[:-1] if line[-1] == u"\n" else line
    #print L
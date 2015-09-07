S=input()
slen=len(S)
list=[]
for i in S.lower():
    if i == "g" or i == "c":
        list.append(i)
print(len(list) / slen * 100)
s = input()
i=0
if len(s)==1:
    print(s,end="")
    print("1")
else:
    j=1
    while i <= len(s)-1:
        while j <= len(s)-1:
            if s[i] != s[j]:
                print(s[i],end="")
                print(j-i,end="")
                i=j
                if j + 1 > len(s)-1:
                    break
                else:
                    j+=1
            else:
                if j==len(s)-1:
                    print(s[i],end="")
                    print(j-i+1,end="")
                    i=j+2
                    j=i
                else:
                    j+=1
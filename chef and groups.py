for t in range(int(input())):
    s= input()
    temp=0
    for i in range(len(s)):
        if s[i]!=s[i-1]:
            temp+=1
    if s[0]=="0":
        temp-=1
    if s[-1]=="0":
        temp-=1
    print((temp//2)+1)

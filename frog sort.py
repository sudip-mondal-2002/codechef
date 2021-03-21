def distinct(l1,l2):
    s=len(set(l1+l2))
    return s
    
for t in range(int(input())):
    n=int(input())
    l=input().split()
    body={}
    for i in l:
        p=i[1:]
        if p in body:
            body[p].append(i[0])
        else:
            body[p]=[i[0]]
    body1=list(body.keys())
    s=0
    for i in range(len(body)):
        for j in range(i+1,len(body)):
            temp=distinct(body[body1[i]],body[body1[j]])
            s+=(temp-len(body[body1[i]]))*(temp-len(body[body1[j]]))
    print(2*s)

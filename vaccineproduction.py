d1,v1,d2,v2,p=map(int,input().split())
days=0
while p>0:
    days+=1
    if days>=d1:
        p=p-v1
    if days>=d2:
        p=p-v2
    
print(days)

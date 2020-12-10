t=int(input())
for i in range(t):
    n,d=map(int,input().split())
    l=list(map(int,input().split()))
    l.append(10)
    l.append(80)
    l.sort()
    part1=l.index(10)
    part2=l.index(80)
    l1=l[:part1]+l[(part2+1):]
    l2=l[(part1+1):part2]
    ans=0 
    if len(l1)%d==0:
        ans+=(len(l1)//d)
    else:
        ans+=(len(l1)//d)+1
    if len(l2)%d==0:
        ans+=(len(l2)//d)
    else:
        ans+=(len(l2)//d)+1
    print(ans)

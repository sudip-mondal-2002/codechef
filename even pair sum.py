t=int(input())
for i in range(t):
    a,b=map(int,input())
    aeven=a//2
    aodd=(a+1)//2
    beven=b//2
    bodd=(b+1)//2
    print(aeven*beven+aodd*bodd)

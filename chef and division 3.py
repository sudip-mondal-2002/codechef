for t in range(int(input())):
    n,k,d=map(int,input().split())
    a=list(map(int,input().split()))
    p=sum(a)//k
    print(min(p,d))

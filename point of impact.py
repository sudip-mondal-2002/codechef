for t in range(int(input())):
    n,k,x,y=map(int,input().split())
    if x==y:
        print(n,n)
    else:
        d=[]
        if x<y:
            d=[[x+n-y,n],[n,n-y+x],[y-x,0],[0,y-x]]
        else:
            d=[[n,y+n-x],[y+n-x,n],[0,x-y],[x-y,0]]
        t=d[(k-1)%4]
        print(t[0],t[1])

for t in range(int(input())):
    number1,number2=map(int,input().split())
    alist=list(map(int,input().split()))
    blist=list(map(int,input().split()))
    
    i=0
    printer=True
    while sum(alist)<=sum(blist):
        alist.sort()
        blist.sort()
        if alist[0]<blist[-1]  :
                temp=blist[-1]
                blist[-1]=alist[0]
                alist[0]=temp
                i+=1
        else:
                printer=False
                print(-1)
                break
    if printer==True:
        print(i)

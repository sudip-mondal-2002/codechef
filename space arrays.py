for t in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    flag=False
    s=0
    for i in range(n):
        temp=a[i]
        s+=temp
        if temp>i+1:
            print("Second")
            flag=True
            break
    if (not flag):
        temp=((n)*(n+1))//2 - s
        if (temp%2)==0:
            print("Second")
        else:
            print("First")

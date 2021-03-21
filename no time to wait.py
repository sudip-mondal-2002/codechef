n,h,x=map(int,input().split())
t=list(map(int,input().split()))
if max(t)+x>=h or x>=h:
    print("YES")
else:
    print("NO")

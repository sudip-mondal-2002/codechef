def find_gcd(x, y): 
    while(y): 
        x, y = y, x % y 
  
    return x
def gcd_arr(l):
    num1=l[0] 
    num2=l[1] 
    gcd=find_gcd(num1,num2) 
  
    for i in range(2,len(l)): 
        gcd=find_gcd(gcd,l[i])
    return(gcd)
def factors(n):
    #print(n)
    if n==0:
        return 1
    x=[]
    for i in range(1,int(n**(1/2))+1):
        if n%i==0:
            x.append(i)
            x.append(n//i)
    return(x)
for t in range(int(input())):
    n,m=map(int,input().split())
    p=list(map(int,input().split()))
    hcf=0
    if m>1:
        hcf=gcd_arr(p)
    else:
        hcf=p[0]
    fact=factors(hcf)
    fact.sort(reverse=True)
    final=0
    for i in fact:
        if i<=n:
            final=n-i
            break
    print(final)

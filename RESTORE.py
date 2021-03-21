n=4*(10**6)
x=list(range(2,n))
for i in range(2,int(n**(1/2))+1):
    for j in x:
        if (j%i)==0 and j!=i:
           x.remove(j)
t=int(input('D'))
for i in range(t):
    N=int(input())
    st=input()
    l=st.split()
    for j in l:
        print(x[j],end=' ')



d=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p']
for t in range(int(input())):
    n=int(input())
    s=input()
    string=''
    for i in range(0,n-3,4):
        string+=d[int(s[i:i+4],2)]
    print(string)

import math


def primeFactors(n):
    d = {}
    while n % 2 == 0:
        n = n // 2
        if 2 in d:
            d[2] += 1 
        else:
            d[2] =  1 
    for i in range(3,int(math.sqrt(n))+1,2):
        while n % i== 0:
            if i in d:
                d[i] += 1 
            else:
                d[i] = 1 
            n = n // i
    if n > 2:
        if n in d:
            d[n] += 1 
        else:
            d[n] = 1
    
    return d
    
def get_all_combs(arr, left):
    global g
    if not left:
        g.append(sum(arr))
    else:
        new = left.pop()
        for i in range(len(arr)):
            newarr = arr.copy()
            newarr[i] *= new 
            get_all_combs(newarr, left.copy())
    


for test in range(int(input())):
    k, x = map(int, input().split())
    d = primeFactors(x)
    if k < len(d):
        p = [item**d[item] for item in d]
        xo = [1]*k
        g = []
        get_all_combs(xo, p)
        print(g)
        print(min(g))
        continue
    
    c2 = 0
    for item in d:
        c2 += item**d[item]
    diff = k - len(d)
        
    c2 += diff
    
    print(c2)



        
        
        
    
    
        
    
    

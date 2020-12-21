for t in range(int(input())):
    n=int(input())
    b=input()
    att=b.count('1')
    if att+120-n>=90:
        print('YES')
    else:
        print('NO')

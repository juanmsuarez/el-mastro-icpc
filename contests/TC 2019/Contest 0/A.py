def mul(a,b,p):
    return (a*b)%p
def pot(b,e,p):
    if (e == 0):
        return 1
    q = pot(b,e//2,p)
    q = mul(q,q,p)
    if e%2!=0:
        return mul(b,q,p)
    else:
        return q


def inv(x,p):
    return pot(x,p-2,p)

t = int(input())
for i in range(t):
    n,p = map(int,raw_input().split())
    if(n>=p):
        print(0)
    else:
        res =p-1
        dif = 1
        for num in range(n+1,p):
            dif*=num
        dif%=p
        res = mul(res,inv(dif,p),p)
        print(res)


M = int(1e9+9)
k, b = map(int, input().split())

def pot(b, p):
    return b**p%k

def sub(a, b):
    return ((a-b)%k+k)%k

m = {}
def f(p, r):
    if p == -1:
        return 0

    if (p, r) not in m:
        act = (2**(p+1)-1+k-r)//k - (2**p-1+k-r)//k
        m[(p, r)] = (f(p-1, r) + f(p-1, sub(r, pot(2, p))) + act) % M 

    return m[(p, r)]

print(f(b-1, 0))

from fractions import gcd

INF = int(1e200)

def iterate():
    pos = s.copy()
    for t in range(CHECKED):
        if min(pos) == max(pos):
            return t, pos[0]+1
        for i, p in enumerate(pos):
            pos[i] = f[i][pos[i]]
    return INF, INF

def cycle(s, f):
    t = 0
    last = []
    while s not in last:
        last.append(s)
        s = f[s]

    beg, end = last.index(s), len(last)
    mod = end - beg
    rest = [-1] * z
    for i in range(beg, end):
        rest[last[i]] = i % mod
    return rest, mod

def chinese(equations):
    r,m = 0,1
    for ri,mi in equations:
        ok = False
        for _ in range(mi):
            if r%mi == ri: 
                ok = True
                break
            else:
                r += m
        if not ok: return INF, INF
        m *= mi // gcd(m, mi)
    return r, m


def checkZoo(zoo):
    equations = [(rest[i][zoo], mod[i]) for i in range(b)]
    r,m = chinese(equations)
    while r < CHECKED: r += m
    return r, zoo+1

# Input
b,z = map(int, input().split())
CHECKED = 2*z

s, f = [], []
for i in range(b):
    line = list(map(lambda n : int(n)-1, input().split()))
    s.append(line[0])
    f.append(line[1:])


ans = iterate()

rest, mod = [], []
for i in range(b):
    r, m = cycle(s[i], f[i])
    rest.append(r)
    mod.append(m)

for zoo in range(z):
    ans = min(ans, checkZoo(zoo))

if ans[0] > INF/2: print("*")
else: 
    t,p = ans
    print(p,t)

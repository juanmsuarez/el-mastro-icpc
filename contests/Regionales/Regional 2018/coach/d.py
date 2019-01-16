n = int(input())
ans = set()

for _ in range(n):
    email = input()
    name, prov = email.split('@')
    name = name.replace('.','')
    plus = name.find('+')
    if plus >= 0: name = name[:plus]
    ans.add('{}@{}'.format(name, prov))

print(len(ans))


fin = open('enchanted.in','r')
fout = open('enchanted.out','w')
s1 = next(fin)[:-1]
s2 = next(fin)[-2::-1]
f1 = next(fin)[:-1]
f2 = next(fin)[-2::-1]

print(s1)
print(s2)
l1 = sorted(zip(s1,s2))
l2 = sorted(zip(f1,f2))
print(l1)
print(l2)
fout.write(('Yes' if l1==l2 else 'No')+'\n')
fin.close()
fout.close()

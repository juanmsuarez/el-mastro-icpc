import math 
a,b=map(int,input().split('.'))
print(int(36000/math.gcd(36000,a*100+b)))

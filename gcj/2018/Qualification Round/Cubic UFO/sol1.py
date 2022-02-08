from math import sin,cos,asin
t=int(input())
for i in range(t):
    a=float(input())
    theta=asin(a**2-1.0)/2.0
    print('Case #%d:'%(i+1))
    print(cos(theta)/2,sin(theta)/2,0)
    print(-sin(theta)/2,cos(theta)/2,0)
    print(0,0,0.5)

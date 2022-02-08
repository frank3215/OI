n,m,v,p=map(int,input().split())
A=sorted(list(map(int,input().split())))[-p::-1]
s=m*v-m*n;u=0
for a in A:
 if a<A[0]-m or s>u*a:break
 s+=a;u+=1
print(p-1+u)


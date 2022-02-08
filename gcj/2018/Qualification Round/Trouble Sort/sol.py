#Python 2
t=input()
for i in range(1,t+1):
    n=input()
    v=map(int,raw_input().split())
    v1=sorted(v[::2])
    v2=sorted(v[1::2])
    v.sort()
    v3=v[::2]
    v4=v[1::2]
    flag=10**6
    for j in range(0,n,2):
        if v1[j/2]!=v3[j/2]:
            flag=j
            break
    for j in range(1,n,2):
        if v2[j/2]!=v4[j/2]:
            flag=min([flag,j])
            break
    print "Case #%d:"%i,
    print "OK" if flag==10**6 else flag

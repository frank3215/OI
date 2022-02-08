n=input()
last=-1
#q=[0]*n
now=0
ans=-1
for i in range(n):
    now=input()
    if now>i or now-last>1:
        print -1
        break
    if now==last+1:
        ans+=1
    elif now<=last:
        ans+=now
    last=now
else:
    print ans
'''
for i in range(n-1,-1,-1):
    if p[i]>q[i]:
        if p[i]>i:
            print -1
            break
        for j in range(i-p[i]+1,i+1):
            q[j]=q[j-1]+1
            ans+=1
    elif p[i]<q[i]:
        print -1
        break
else:
    print ans
'''

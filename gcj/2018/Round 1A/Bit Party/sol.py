t = input()
r=b=c=0
s=[]
def test(time):
    l=[]
    for i in range(c):
        cr=s[i]
        if cr[0]>=time:
            break
        n=(time-cr[0])/cr[1]
        if n==0: continue
        l.append(min([cr[2],n]))
    l.sort(reverse=True)
    return sum(l[:r]) >= b
for t in range(t):
    print "Case #%d:"%(t+1),
    r,b,c=map(int,raw_input().split())
    s=[] #(p,s,m) t=s*n+p
    for i in range(c):
        s.append(map(int,raw_input().split())[::-1])
    s.sort()
    low=1
    high=10**19
    while low<high:
        mid=(low+high)/2
        if test(mid):
            high=mid
        else:
            low=mid+1
    print low

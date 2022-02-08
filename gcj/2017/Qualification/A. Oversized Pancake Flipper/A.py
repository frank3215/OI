#Small Dataset

def trans(ch):
    m=2**len(ch)
    re=0
    for a in ch:
        m/=2
        if a=="+":
            re+=m
    return re

def flip(a):
    b=""
    i="+-"
    for c in a:
        b=b+i[(i.find(c)+1)%2]
    return b

import sys
fp = file(sys.argv[1])
for case in range(int(fp.next())):
    (st, a) = fp.next().split()
    a=int(a)
    b=len(st)
    d=[0]*(2**b)
    s=[(0,st)]
    g="+"*b
    while len(s)>0:
        p=s.pop(0)
        c=p[1]
        t=p[0]
        for i in range(0,b-a+1):
            temp=c[0:i]+flip(c[i:i+a])+c[i+a:]
            if d[trans(temp)]==0:
                d[trans(temp)]=1
                s.append((t+1,temp))
        if c==g:
            break
        t="IMPOSSIBLE"
    print "Case #%d: %s" % (case+1,t)
fp.close()

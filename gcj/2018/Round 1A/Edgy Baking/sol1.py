t=input()
for t in range(t):
    print "Case #%d:"%(t+1),
    n,p=map(int,raw_input().split())
    c=[]
    tp=0
    for i in range(n):
        c.append(map(int,raw_input().split()))
        tp+=sum(c[-1])*2
#print tp
    w,h=c[-1]
    mx=(w**2+h**2)**0.5
    c=min( [(p-tp)/(min(c[-1]))/2,n] )
#print mx,c
    print min([p-tp,mx*c*2])+tp 

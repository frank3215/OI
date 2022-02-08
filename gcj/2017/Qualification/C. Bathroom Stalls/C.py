#Small Dataset
def findd(a):
    maxx=0
    s=0
    e=0
    s1=0
    e1=0
    count=0
    for i in range(0,len(a)):
        if a[i]!=0:
            count=-1
            s1=i
            e1=i-1
        count+=1
        e1+=1
        if count>maxx:
            s,e=s1,e1
            maxx=count
    #print s,e,maxx
    return [(s+e+1)/2,(e-s)/2,(e-s-1)/2]

def moni(a,b):
    l=[-1]+[0]*a+[-1]
    for i in range(1,b):
        k=findd(l)[0]
        l[k]=i
    return findd(l)[1:]

#MAIN
import sys
fp = file(sys.argv[1])
for case in range(int(fp.next())):
    (stalls, num) = fp.next().split()
    l=moni(int(stalls),int(num))
    print "Case #%d: %s %s" % (case+1, l[0], l[1])
fp.close()

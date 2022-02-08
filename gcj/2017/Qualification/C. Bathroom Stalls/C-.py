#Small Dataset 2
def moni(a,b):
    l=[a]
    if b>a/2:
        return [0,0]
    for i in range(1,b):
        l3=l[0]/2
        l4=(l[0]-1)/2
        del l[0]
        l.extend([l3,l4])
        print l
        l.sort(reverse=True)
    return [l[0]/2,(l[0]-1)/2]

moni(10000,2000)

#MAIN
import sys
fp = file(sys.argv[1])
for case in range(int(fp.next())):
    (stalls, num) = fp.next().split()
    l=moni(int(stalls),int(num))
    print "Case #%d: %d %d" % (case+1,l[0], l[1])
fp.close()

#A-small
import sys
fp = file(sys.argv[1])
for case in range(int(fp.next())):
    (S,n) = fp.next().split()
    S,n=int(S),int(n)
    s=[0]*n
    v=[0]*n
    for i in range(n):
        l=fp.next().split()
        s[i]=int(l[0])
        v[i]=int(l[1])
    # ^
    # | .(x1,y1)
    #-+-->
    # |
    m=0
    for i in range(n):
        m=max([m,(int(S)-s[i])/float(v[i])])
    print "Case #%d: %.8f" % (case+1, S/m)
fp.close()

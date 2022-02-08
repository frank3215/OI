#small-1
#!/usr/bin/python
import sys
possib
fp = file(sys.argv[1])
for case in range(int(fp.next())):
    (N, K) = fp.next().split()
    train=float(fp.next())
    pos=fp.next().split()
    possi=[float(i) for i in pos]+[1.0]
    possi.sort()
    for i in range(0,len(possi)-1):
        spend=min(train,(possi[i+1]-possi[i])*(i+1))
        train-=spend
        possi[:i+1]=[possi[i]+spend/(i+1)]*(i+1)
        if train==0:
            break
    res=1.0
    for i in possi[:-1]:
        res*=i
    print "Case #%d: %.20f" % (case+1, res)
fp.close()

#!/usr/bin/python
import sys
fp = file(sys.argv[1])
print fp
for case in range(int(fp.next())):
    (num, src, trg) = fp.next().split()
    n = 0
    for c in num:
        n=n*len(src)+src.find(c)
    res = ""
    while n:
        res = trg[n%len(trg)] + res
        n/=len(trg)
    print "Case #%d: %s" % (case+1, res)
fp.close()
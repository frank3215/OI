#!/usr/bin/python
import sys
fp = file(sys.argv[1])
for case in range(int(fp.next())):
    (num, src, trg) = fp.next().split()
    #CODE HERE
    print "Case #%d: %s" % (case+1, res)
fp.close()

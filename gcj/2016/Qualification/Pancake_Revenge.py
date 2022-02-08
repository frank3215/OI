#!/usr/bin/python
import sys
fp = file(sys.argv[1])
for case in range(int(fp.next())):
 pc = fp.next()
 pan=pc[0]
 g=1
 for i in range(0,len(pc)-1):
  if pc[i]!=pan:
   pan=pc[i]
   g+=1
 g=g if pc[len(pc)-2]=="-" else g-1
 print "Case #%d: %s" % (case+1, g)
fp.close()

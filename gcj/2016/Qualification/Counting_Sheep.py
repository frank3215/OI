#!/usr/bin/python
import sys
fp = file(sys.argv[1])
for case in range(int(fp.next())):
 num = int(fp.next())
 l=[]
 m=10
 for i in range(1,101):
  for j in range(0,10):
   if str(j) in str(num*i) and not j in l:
    m-=1
    l.append(j)
   if m==0:
    res=num*i
    break
  if m==0:
   break
 if m!=0:
  res="INSOMNIA"
 print "Case #%d: %s" % (case+1, res)
fp.close()

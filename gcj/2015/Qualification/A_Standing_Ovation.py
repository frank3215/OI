import sys
fp = file(sys.argv[1])
print fp
for case in range(int(fp.next())):
 (smax,s) = fp.next().split()
 ans=0
 aud=0
 for i in range(0,len(s)):
  if aud<i:
   ans+=i-aud
   aud=i
  if aud>=i:
   aud+=int(s[i])
 print "Case #%d: %s" % (case+1,ans)
fp.close()

#Large Dataset
#INITIALIZE
def istidy(n):
  sn=str(n)
  t=0
  for i in range(0,len(sn)):
    if t > int(sn[i]) or int(sn[i])==0:
      return i
    t=int(sn[i])
  return "True"

def main(n):
  if istidy(n)=="True":
    return n
  sn=str(n)
  i=istidy(n)
  for j in range(len(sn)-1,-1,-1):
    if istidy(n) == "True":
      return n
    if j<0:
      break
    n-=(int(sn[j])+1)*10**(len(sn)-j-1)
    sn=str(n)
#MAIN
import sys
fp = file(sys.argv[1])
for case in range(int(fp.next())):
  num=int(fp.next())
  print "Case #%d: %s" % (case+1,main(num))
fp.close()
'''
def find(n):
  flag=False
  for i in range(0,len(str(n))-1):
    if str(n)[i+1]<str(n)[i] or str(n)[i+1]==0:
      flag=True
      i=i+1
      break
  if flag:
    c=""
    while j>=0:
      if j==i-1:
        if int(str(n)[i])-1<=0:
          for l in range(i-1,-1,-1):
            if int(str(n)[l])-1!=0:
              j=l+1
              break
            if int(str(n)[l])-1<=0 and l!=0:
              n-=10**(l+1)-10**(l)
            elif int(str(n)[l])-1<=0 and l==0:
              n+=10**l
        c=c+str(int(str(n)[i])-1)
        continue
      if j>=i:
        c=c+"9"
      c=c+str(n)[i]
      j-=1
    print c
    print find(c)
  else:
    return n
'''
'''
#Small Dataset
#INITIALIZE
a=[]
for i in range(0,10):
  for j in range(0,i+1):
    for k in range(0,j+1):
      if str(i+j*10+k*100).find("0") == -1:
        a.append(i+j*10+k*100)
a.sort()
#MAIN CODE
import sys
fp = file(sys.argv[1])
for case in range(int(fp.next())):
  num = int(fp.next())
  res=0
  for i in a:
    if i>num:
      break
    res=i
  print "Case #%d: %s" % (case+1, res)
fp.close()
'''

def istidy(n):
  sn=str(n)
  t=0
  for i in range(0,len(sn)):
    if t > int(sn[i]) or int(sn[i])==0:
      return i
    t=int(sn[i])
  return "True"

def main(n):
  if istidy(n)==True:
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

k=raw_input(">>:")
j=int(k)
print main(j)

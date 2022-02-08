#!/usr/bin/python
import sys
'''
num=["ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"]
def dict():
  #dict={}
  for i in range(0,10):
    #dict={}
    for j in num[i]:
      dict[j]=dict.get(j,0)+1
    num[i]=dict
  return dict
print dict()
{'E': 9, 'G': 1, 'F': 2, 'I': 4, 'H': 2, 'O': 4, 'N': 4, 'S': 2, 'R': 3, 'U': 1, 'T': 3, 'W': 1, 'V': 2, 'X': 1, 'Z': 1}
'''

num=[{'R': 1, 'Z': 1, 'E': 1, 'O': 1}, {'E': 1, 'O': 1, 'N': 1}, {'O': 1, 'T': 1, 'W': 1}, {'H': 1, 'R': 1, 'E': 2, 'T': 1}, {'R': 1, 'U': 1, 'O': 1, 'F': 1}, {'I': 1, 'V': 1, 'E': 1, 'F': 1}, {'I': 1, 'X': 1, 'S': 1}, {'S': 1, 'N': 1, 'E': 2, 'V': 1}, {'I': 1, 'H': 1, 'E': 1, 'T': 1, 'G': 1}, {'I': 1, 'E': 1, 'N': 2}]
p="8426057193"

def dict(inp):
  d={}
  for i in inp:
    d[i]=d.get(i,0)+1
  return d

def find(d):
  l=[]
  for i in p:
    flag=True
    mi=100000
    for j in num[int(i)].keys():
      if d.get(j,0)<num[int(i)][j]:
        flag=False
        break
      else:
        mi=min(mi,d.get(j,0)/num[int(i)][j])
    if flag:
      for j in num[int(i)].keys():
        k=d[j]-mi*num[int(i)].get(j,1)
        d[j]=k
      for v in range(0,mi):
        l.append(i)
  return l

fp = file(sys.argv[1])
for case in range(int(fp.next())):
  n=fp.next()[:-1]
  l=sorted(find(dict(n)))
  res=""
  for i in l:
    res=res+i
  print "Case #%d: %s" % (case+1, res)
fp.close()

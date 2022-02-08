from random import randint as ri
print 100
for i in range(100):
    print 100
    l=[]
    for j in range(99):
        l.append(ri(0,98))
    l+=[99]
    l.sort()
    last=-1
    for j in range(100):
        print l[j]-last,
        last=l[j]
    print

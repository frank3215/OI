t=input()
for j in range(t):
    d,i=raw_input().split()
    d=int(d)
    c=i.count('C')
    s=i.count('S')
    print "Case #%d:"%(j+1)
    if s>d:
        print 'IMPOSSIBLE'
        continue
    if not c:
        print 0
    else:
        x=i.find('C')
        y=i[x:].count('S')
        if y*2+s<=d:
            print 0
        else:
            print y-(d-s)

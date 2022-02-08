'''
def moni(times,seats,num,expected,case):
    if times==0:
        return num
    if seats==0:
        return num
    if num == -1:
        return -1
    #print indent,num,[seats/2,(seats-1)/2]
    if num == expected:
        print "Case #%s: %s %s"%(case+1,seats/2,(seats-1)/2)
        return -1
    num+=1
    #indent=indent+"  "
    return moni(times-1,(seats-1)/2,moni(times-1,seats/2,num,expected,case),expected,case)
moni(9,500,1,256,98)
'''
def insertt(l,num):
    le=len(l)/2
    i=len(l)/2
    l.append(num)
    while 1:
        i/=2
        if l[le]<num:
            le-=i
        if num<l[le]:
            le+=i
        if l[le]>=num>=l[le]:
            del l[len(l)-1]
            l.insert(le+1,num)
            break
        if i == 0:
            i=2
    return l

def moni(people,expected,l):
    seats=l.pop(0)
    if people==expected:
        print l,seats
        return [seats/2,(seats-1)/2]
    #l.extend([seats/2,(seats-1)/2])
    l=insertt(l,seats/2)
    l=insertt(l,(seats-1)/2)
    #print l
    #l.sort(reverse=True)
    return moni(people+1,expected,l)
print moni(1,2000,[20000])
'''    
import sys
import math
fp=file(sys.argv[1])
for case in range(int(fp.next())):
    (seats,expected) = fp.next().split()
    moni(int(math.log(int(expected),2)+1) ,int(seats),1,int(expected),case)
'''

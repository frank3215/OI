from math import log
def node(num):
    return [int(log(num,2)+1), num-2**int(log(num,2))]

def mother(line,num):
    return [line-1,num/2,num%2]

def insertt(seats,num):
    return [seats/2,(seats-1)/2][num]

def findd(seats,people):
    l=node(people)
    m=[]
    line=l[0]
    num=l[1]
    for i in range(l[0]):
        m.insert(0,mother(line,num)[2])
        line-=1
        num/=2
    #print m
    for i in range(l[0]):
        if i==0:
            temp=seats
            continue
        #print m[i],temp/2,(temp-1)/2
        temp=insertt(temp,m[i])
    #print "TEMP",temp
    temp=max([1,temp])
    return ([temp/2,(temp-1)/2])
#MAIN
import sys
fp = file(sys.argv[1])
for case in range(int(fp.next())):
    (stalls, num) = fp.next().split()
    l=findd(int(stalls),int(num))
    print "Case #%d: %d %d" % (case+1,l[0], l[1])
fp.close()

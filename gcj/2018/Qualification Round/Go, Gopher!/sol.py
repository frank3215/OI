import sys
t=input()
for i in range(t):
    a=input()
    flag=0
    for j in range(2,71,3):
        o=[0]*9
        while o!=[1]*9:
            print 2,j
            sys.stdout.flush()
            x,y = map(int,raw_input().split())
            if x<=0 and y<=0:
                flag=1
                break
            o[(x-1)*3+y-j+1]=1
        if flag:
            break
        
    

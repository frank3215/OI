#Small
#d=[0]*1440
a=[[0,10],[1420,1440],[90,100]]
#a_lapse=[[1440,0,1440]]
a.sort()
b=[[550,600],[900,950],[100,150],[1050,1400]]
b.sort()
B=[[0,1440,0]]
#b_lapse=[[1440,0,1440]]
d=[[0,1440,0]]
plan=[]
for i in a:
    j=0
    #k=0
    while d[j][1]<i[0]:
        j+=1
    #while a_lapse[k][2]<i[0]:
        #k+=1
    #a_lapse.insert(k+1,[-a_lapse[k][1]+i[0],a_lapse[k][1],i[0]])
    #a_lapse[k]=[-i[1]+a_lapse[k][0],i[1],a_lapse[k][0]]
    d.insert(j+1,[i[1],d[j][1],0])
    d[j]=[d[j][0],i[0],0]
    d.insert(j+1,i+[1])
A=d[:]
for i in b:
    j=0
    k=0
    while d[j][1]<i[0]:
        j+=1
    while B[k][1]<i[0]:
        k+=1
    #print b_lapse
    #b_lapse.insert(k+1,[-i[1]+b_lapse[k][0],i[1],b_lapse[k][0]])
    #b_lapse[k]=[-b_lapse[k][1]+i[0],b_lapse[k][1],i[0]]
    d.insert(j+1,[i[1],d[j][1],0])
    d[j]=[d[j][0],i[0],0]
    d.insert(j+1,i+[2])
    B.insert(k+1,[i[1],B[k][1],0])
    B[k]=[B[k][0],i[0],0]
    B.insert(k+1,i+[2])
'''
a_lapse.sort(reverse=True)
b_lapse.sort(reverse=True)
'''
print A
print B
print d

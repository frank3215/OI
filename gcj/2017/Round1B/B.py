#Problem B
import sys
fp = file(sys.argv[1])
for case in range(int(fp.next())):
    L = fp.next().split()
    col="RYB"
    N=int(L[0])
    num=[int(L[i]) for i in range(1,7)]
    maxc=max(num)
    spaces=[0]*maxc
    arrange=[col[num.index(maxc)/2-1]]*sum(num)
    if maxc>N/2:
        res="IMPOSSIBLE"
    else:
        dex=num.index(maxc)
        colour=col[dex/2]
        unics=""
        for i in range(maxc+1):
            if i!=maxc:
                arrange[int(N*i/float(maxc))]=colour
            spaces[i-1]=[int(N*i/float(maxc))-int(N*(i-1)/float(maxc))-1,int(N*(i-1)/float(maxc))]
        #spaces[-1]=[int(N*i/float(maxc))-int(N*(i-1)/float(maxc))-1,int(N*(i-1)/float(maxc))]
        colour=col[dex/2-2]
        s=0
        for i in spaces:
            s+=i[0]/2
        n=num[dex-4]-s
        for i in spaces:
            if n:
                for j in range(0,i[0],2):
                    arrange[j+i[1]+1]=colour
                n-=(i[0]%2+1)/2
            else:
                for j in range(1,i[0],2):
                    arrange[j+i[1]+1]=colour
        res="".join(arrange)
    print "Case #%d: %s" % (case+1, res)
fp.close()

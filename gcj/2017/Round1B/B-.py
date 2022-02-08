#Problem B
c="ROYGBV"
colours=["R","RY","Y","YB","B","RB"]
pri_col="RYB"
N=6
num=[2,0,2,0,2,0]
manes=[num[0]+num[1]+num[5],num[1]+num[2]+num[3],num[3]+num[4]+num[5]]
arrange=["."]*6
maxc=max(manes)
if maxc>N/2 or (num[1]>num[]:
    print "IMPOSSIBLE"
else:
    colour=pri_col[manes.index(maxc)]
    unics=""
    for i in range(maxc):
        arrange[int(N*i/float(maxc))]=

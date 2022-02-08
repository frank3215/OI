n=input()
jj=0
for t in range(n):
    print 'Case #%d:'%(t+1),
    r,c,h,v=map(int,raw_input().split())
    w=[]
    tot=0
    cr=[0]*r
    for j in range(r):
        w.append(raw_input())
        cr[j]=w[-1].count('@')
        tot+=cr[j]
    '''
    if tot%((h+1)*(v+1))!=0:
        print('IMPOSSIBLE')
        continue'''
    cnt= 0
    pr = tot/(h+1)
    pc = tot/(v+1)
    pp = pc/(h+1)
    cv = [0]
    flag=0
    tot=0
    for j in range(c):
        for i in range(r):
            cnt += w[i][j]=='@'
        if cnt == pc:
            cnt-=pc
            cv.append(j+1)
        elif cnt > pc:
            flag=1

    cnt=0
    cc = [0]*c
    for j in range(r):
        if flag: break
        cnt+=cr[j]
        for i in range(c):
            cc[i] += w[j][i]=='@'
        if cnt == pr:
            cnt -= pr
            tot = 0
            for i in range(v):
                tnc = sum(cc[cv[i]:cv[i+1]])
                if tnc != pp:
                    cnt = pr+1
                    break
            cc=[0]*c
        if cnt > pr:
            flag=1
    print ('IM' if flag else '')+'POSSIBLE'

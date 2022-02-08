for i in range(1,input()+1):
    print "Case #%d:"%i,
    c=input();b=map(int,raw_input().split())
    #b[0]-=1;b[-1]-=1
    if b[0]==0 or b[c-1]==0 or sum(b)!=c:
        print "IMPOSSIBLE"
        continue
    a=0;ans=[['.']*c]
    for j in range(c):
        ans.append(ans[0][:])
    for j in range(c):
        for k in range(b[j]):
            if k+a>j:
                for l in range(k+a,j,-1):
                    ans[k+a-l][l]='/'
            elif k+a<j:
                for l in range(k+a,j):
                    ans[l-k-a][l]='\\'
        a+=b[j]
    for ln in range(c+1):
        if ans[ln]==['.']*c:
            break
    print ln+1
    for j in range(ln+1):
        print ''.join(ans[j])


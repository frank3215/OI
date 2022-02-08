def run(grid):
    grid=grid.split('\n')
    ln=len(grid[0])
    nm=[1]*ln
    for l in grid:
        nx=[0]*ln
        for i in range(0,ln):
            if l[i]=='.':
                nx[i]+=nm[i]
            if l[i]=='/':
                nx[i-1]+=nm[i]
            if l[i]=='\\':
                nx[i+1]+=nm[i]
        nm=nx
    return nm
print 100
for i in range(100):
    raw_input()
    a=''
    for i in range(101):
        a+=raw_input()+('\n' if i!=100 else '')
    print 100
    print ' '.join(map(str,run(a)))

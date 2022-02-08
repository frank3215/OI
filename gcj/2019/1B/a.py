n = int(input())
for t in range(1, n+1):
    p, q = map(int, input().split())
    for i in range(p):
        s = input()
        x, y = map(int, s.split()[:2])
        d = s.split()[-1]
        l.append((x, y, d))
        lx.append(x)
        ly.append(y)
    sort(lx)
    sort(ly)

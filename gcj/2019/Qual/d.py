import sys
t = input()
def get(l, w):
    return (('0'*w+'1'*w)*(l/(2*w)+1))[:l]

def solve(l, w, res):
    ans = []
    num = l - len(res[0])
#print l, num, w, res
    if not l: return ans
    if w == 1:
        if res[0].find('0') == -1: ans.append(0)
        if l > 1 and res[0].find('1') == -1: ans.append(1)
#print ans
        return ans
    mid = res[0].find('1')
    if mid == -1: mid = len(res[0])
    left = map(lambda s: s[:mid], res[1:])
    right = map(lambda s: s[mid:], res[1:])
    ans += solve(min(l, w), w/2, left)
#print '', l, num, w, res
#print '0:', ans
    ans += map(lambda x: x+w, solve(l - min(l, w), w/2, right))
#sys.stderr.write(' %d %d %d %s\n%s\n'%(l, num, w, repr(res), repr(ans)))
    return ans

for i in range(t):
    n, b, f = map(int, raw_input().split())
    res = []
    for k in range(5):
        w = 2**(4-k)
        print get(n, w)
        sys.stdout.flush()
        s = raw_input()
        res.append(s)
#if not k:
#pre = 0
#for j in range(siz):
#nxt = s[pre:].find(str((j+1)%2))+pre if j != siz-1 else n
#pos2.append((pre, nxt))
#pre = nxt
#print res
    ans = []
    pre = 0
    s = res[0] 
    for l in range(0, n, 32):
        nxt = s[pre:].find('10')+pre+1
        if nxt==pre: nxt = n
        ans += map(lambda x: x+l, solve(min(l+32, n)-l, 16, map(lambda l: l[pre:nxt], res)))
        pre = nxt

#sys.stderr.write(str(b)+'\n'+' '.join(map(str, ans))+'\n')
    print ' '.join(map(str, ans))
    sys.stdout.flush()
    if input() == -1:
        break

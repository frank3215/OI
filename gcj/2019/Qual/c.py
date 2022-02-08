t = input()
def gcd(a, b): return gcd(b, a%b) if b else a
for i in range(1, t+1):
    n, l = map(int, raw_input().split())
    a = map(int, raw_input().split())
    c = [0]*(l+1)
    for j in range(1, l):
	if a[j] != a[j-1]:
	    c[j] = gcd(a[j], a[j-1])
	    for k in reversed(range(j)):
		c[k] = a[k]/c[k+1]
	    for k in range(j+1, l+1):
		c[k] = a[k-1]/c[k-1]
	    break
    b = sorted(list(set(c)))
    print "Case #%d:"%i, ''.join(map(lambda x: chr(ord('A')+b.index(x)), c))

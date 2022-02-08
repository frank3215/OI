import math

f = open("software5.in")
a = []
for i in range(3): f.readline()
mn = 2**31
while 1:
	s = f.readline()
	if not s: break
	a.append(int(s))
	if (int(s) > 10): mn = min(mn, int(s))

f = open("software5.ans")
mx = 0
b = []
while 1:
	s = f.readline()
	if not s: break
	b.append(int(s))
	mx = max(mx, int(s))

print mx, mn
pos = a.index(mn)
ans = b[a.index(mn)]
p = pow(19, pos)
p-=ans
while 1:
	mx += 1
	if p%mx == 0:
		print mx
		break

#print zip(a,b)[:3]
"""
for i in range(2, 1000000):
	mx += 1
	ok = 1;
	for i in range(0, len(a)):
		if pow(19, a[i], mx) != b[i]:
			ok = 0
			break
	if ok:
		print mx
		exit(0)
"""

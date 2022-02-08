t = input()
for i in range(t):
    s = raw_input()
    n = int(s)
    a = sum(map(lambda i: 10**(len(s)-1-i) if s[i]=='4' else 0, range(len(s))))
    print "Case #%d:"%(i+1), a, n-a
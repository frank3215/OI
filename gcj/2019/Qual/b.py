t = input()
tot = ord("E")+ord("S")
for i in range(t):
    n = input()
    s = raw_input()
    print "Case #%d:"%(i+1), ''.join(map(lambda c: chr(tot-ord(c)), list(s)))

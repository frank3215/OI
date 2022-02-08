
ans = '''
bbhi
cchi
fgdd
fgee

bbccj
ddg.j
eegff
..hik
..hik

bbccdd
eeffgg
hij...
hij...
...klm
...klm

bbccdd.
eeff..m
gghh..m
....ikn
....ikn
....jlo
....jlo
'''
n = input()

if n == 2:
	print(-1)
elif n == 3:
	print("aa.\n..b\n..c\n");

l = map(lambda x: x.split('\n'), ans.split('\n\n'))
pre = [0]*n



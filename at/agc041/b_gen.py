from cyaron import *

while 1:
	io = IO('b.in', 'b.out')
	n = 5
	m = 5
	v = randint(1,n-1)
	p = randint(1,n-1)
	io.input_writeln(n,m,v,p)
	for i in range(n):
		io.input_write(randint(0,10))

	Compare.program('./b', input=io, std_program='./b_std')
	print("AC")

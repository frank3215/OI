from cyaron import *

try:
	while 1:
		n = 10
		io = IO("a.in", "a.out")
		io.input_writeln(n)
		t = Graph.tree(n, weight_limit=n)
		for e in t.iterate_edges():
			io.input_writeln(e)
		m = randint(1, n)
		io.input_writeln(m)
		for i in range(m):
			io.input_writeln(randint(2, n))
		Compare.program("./a", input=io, std_program="./std")
finally:
	pass

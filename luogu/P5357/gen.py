from cyaron import *

while 1:
	io = IO("input", "output")
	n = 10
	io.input_writeln(n)
	for i in range(n):
		io.input_writeln(String.random(20000))
	io.input_writeln(String.random(2000000))
	Compare.program("./a", std_program="./std", input=io)
	print("AC")

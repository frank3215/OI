from cyaron import *

while 1:
    io = IO(file_prefix="test")
    t = 100
    io.input_writeln(t)
    for i in range(t):
        n = 100
        io.input_writeln(n)
        for j in range(n):
            a = randint(1, n-1)
            b = randint(a+1, n)
            io.input_writeln(a, b)
        for j in range(n):
            g = randint(0, 2)
            io.input_write(g)
        io.input_write('\n')
    print("Done!")
    Compare.program("./d", input=io, std_program="./d_std")
    break

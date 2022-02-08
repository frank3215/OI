from cyaron import *

while 1:
    io = IO(file_prefix="test")
    t = 1
    io.input_writeln(t)
    for i in range(t):
        n = 5
        MX = 10
        io.input_writeln(n)
        for j in range(n):
            a = randint(1, MX)
            b = randint(1, MX)
            io.input_writeln(a, b)
    print("Done!")
    Compare.program("./c", input=io, std_program="./c_std")

from cyaron import *

flag = 'B'

if flag == 'A':
    while 1:
        io = IO(file_prefix="test")

        T = 10
        io.input_writeln(T)
        for _ in range(T):
            A = 7
            io.input_writeln(A)
            for __ in range(A):
                l = randint(1, 5)
                io.input_writeln(String.random(l, charset="RPS"))

        Compare.program("./a", input=io, std_program="./a.brute")

if flag == 'B':
    io = IO(file_prefix="test")
    T = 2
    io.input_writeln(T, 150)
    for _ in range(T):
        for __ in range(150):
            io.input_writeln('A')


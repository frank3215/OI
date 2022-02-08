'''
mx = 20
with open('input', 'w') as a:
    a.write('%d\n'%(mx*(mx-1)/2))
    for i in range(1, mx):
        for j in range(i, mx):
            a.write('%d %d\n'%(i, j))
'''
from cyaron import *
from string import *

while 1:
    io = IO(file_prefix="test")

    t = 10
    io.input_writeln(t)
    for _ in range(t):
        n = randint(1, 6)
        io.input_writeln(n)
        for __ in range(n):
            l = randint(1, 5)
            io.input_writeln(String.random(l, charset=ascii_uppercase))

    Compare.program("./c", input=io, std_program="./std")

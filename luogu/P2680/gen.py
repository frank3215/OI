from cyaron import *

try:
    while 1:
        io = IO("input", "answer");
        n = 10
        m = 10
        io.input_writeln(n, m)
        T = Graph.tree(n, weight_limit=n);
        for e in T.iterate_edges():
            io.input_writeln(e)
        for i in range(m):
            u = randint(2, n)
            v = randint(1, u-1)
            io.input_writeln(u, v);
        io.output_gen("./std");
        Compare.program("./a", input=io, std=io)
        print("OK")
finally:
    pass

from cyaron import *

io = IO("input", "answer")
n = 500000
g = Graph.tree(n)

io.input_writeln(n)
for e in g.iterate_edges():
    io.input_writeln(e.start, e.end)

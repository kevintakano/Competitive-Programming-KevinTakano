import sys

r = sys.stdin.readline
p = sys.stdout.write

b, N = map(int,r().split())


fathers = [k for k in range(0,b+1)]

def find(x):
    if fathers[x] == x:
        return x
    return find(fathers[x])

def join(x,y):
    fathers[find(x)] = find(y)

for n in range(0,N):
    l =  r().split()
    op, x, y = l
    x = int(x)
    y = int(y)
    res = 'N'
    visited = set()

    if op == 'F':
        join(x,y)

    if op == 'C':
        res = 'S' if find(x) == find(y) else 'N'
        p(res + '\n')


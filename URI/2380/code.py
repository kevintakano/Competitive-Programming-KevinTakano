import sys

r = sys.stdin.readline
p = sys.stdout.write

b, N = map(int,r().split())

banks = {k : set() for k in range(1,b+1) }
visited = set()

def is_the_same(cur,final):
    # print('  %d %d' % (cur,final))
    visited.add(cur)
    if  final in banks[cur]:
        #print(' when cur = ',cur)
        #print(' and fin = ',final)
        return True
    else:
        allbanks = banks[cur]
        for connected in allbanks:
            #print(' visited',visited)
            # print(' connected = ' ,connected)
            if (connected not in visited):
                return is_the_same(connected,final)

    return False

def evaluate(cur,final):
    visited = set()
    return is_the_same(cur,final)

for n in range(0,N):
    l =  r().split()
    op, x, y = l
    x = int(x)
    y = int(y)
    res = 'N'
    visited = set()

    if op == 'F':
        banks[x].add(y)
        banks[y].add(x)

    # print('%c %d %d' % (op,x,y))
    # print(banks)

    if op == 'C':
        if evaluate(x,y) or evaluate(y,x):
            res = 'S'
        else:
            res = 'N'
        p(res + '\n')


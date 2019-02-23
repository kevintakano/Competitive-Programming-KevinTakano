import sys

xs =  [i+1 for i in range(0,50*1000 + 1)]
index_map = [ i + 1 for i in range(0,50*1000 + 1)]

def swap(i,j):
    tmp = xs[i]
    xs[i] = xs[j]
    xs[j] = tmp

def swap_map(i,j):
    tmp = index_map[i]
    index_map[i] = index_map[j]
    index_map[j] = tmp

def apply_reversed(xs,i,j):
    x = i
    y = j
    while(y > x):
        # print('%d %d' % (x,y))
        swap(x,y)
        # print('before')
        # print(json.dumps(index_map,indent=4))
        # swap_map(xs[x],xs[y])
        # print('after')
        # print(json.dumps(index_map,indent=4))
        y -= 1
        x += 1

    return xs

n = 1
while True:
    N = int(sys.stdin.readline())

    if N == 0: break
    R = int(sys.stdin.readline())

    for i in range(0,N):
        xs[i] = i + 1
        index_map[i+1] = i + 1


    print(xs[:N])
    for r in range(0,R):
        i,j = map(int,sys.stdin.readline().split())
        xs = apply_reversed(xs,i-1,j-1)
        print(xs[:N],end='')
        print(' %d %d' % (i,j))

    Q = int(sys.stdin.readline())

    res = 'Genome %d' % (n) + '\n'

    for q in range(0,Q):
        a = int(sys.stdin.readline())
        res += str(index_map[a]) + '\n'

    sys.stdout.write(res)

    n += 1


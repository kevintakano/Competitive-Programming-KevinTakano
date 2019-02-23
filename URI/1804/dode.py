import sys
import bisect

MAX = 100001

buggy = []
index_map = {}

r = sys.stdin.readline
p = sys.stdout.write

n = int(r())

buggy = list(map(int,r().rstrip().split()))
for i in range(1,n+1):
    index_map[i] = i

#print(buggy)
#print(sum(buggy))
#print('index_map' , index_map)

for line in sys.stdin:
    op, abd  = line.split()
    abd = int(abd)
    if op == 'a':
        if abd in index_map:
            del index_map[abd]
    else:
        keys = sorted(list(index_map.keys()))

        pos_abd = bisect.bisect_left(keys,abd)
        #print('abd',abd)
        #print('pos_abd',pos_abd)
        #print('keys[:pos_abd] ' , keys[:pos_abd])
        s = 0
        for k in keys[:pos_abd]:
            s += buggy[k-1]

        p(str(s) + '\n')

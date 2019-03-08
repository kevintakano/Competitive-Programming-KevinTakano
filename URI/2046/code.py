from collections import defaultdict
from math import sqrt
from math import pow

from collections import defaultdict
from heapq import *

coordinates = dict()

def dijkstra(edges, f, t):
    g = defaultdict(list)
    for l,r,c in edges:
        g[l].append((c,r))

    q, seen, mins = [(0,f,())], set(), {f: 0}
    while q:
        (cost,v1,path) = heappop(q)
        if v1 not in seen:
            seen.add(v1)
            path = (v1, path)
            if v1 == t:
                return (cost, path)

            for c, v2 in g.get(v1, ()):
                if v2 in seen: continue
                prev = mins.get(v2, None)
                next = cost + c
                if prev is None or next < prev:
                    mins[v2] = next
                    heappush(q, (next, v2, path))

    return (float("inf"),[])

def distance(node_a,node_b):
    return sqrt( pow((node_a[0]-node_b[0]),2) + pow((node_a[1]-node_b[1]),2))



def get_node_by_index(node1_idx,node2_idx):
    coord_1 = coordinates[node1_idx]
    coord_2 = coordinates[node2_idx]

    if coord_1[0] < coord_2[0]:
        return node1_idx
    elif coord_1[0] > coord_2[0]:
        return node2_idx
    elif coord_1[0] == coord_2[0]:
        if coord_1[1] < coord_2[1]:
            return node1_idx
        if coord_1[1] > coord_2[1]:
            return node2_idx
        else:
            return node2_idx

def get_minor(possibles_path):

    possibles_sorted = sorted(possibles_path,key=lambda x: x[1])

    first_distance = possibles_sorted[0][1]
    get_equals = [el for el in possibles_sorted if first_distance == el[1]]

    if len(get_equals) > 1:
        mini_el = get_equals[0]
        idx_mini = mini_el[0]

        for el in get_equals[1:]:
            idx_el = el[0]
            idx_mini = mini_el[0]
            idx_mini = get_node_by_index(idx_el,idx_mini)
        return idx_mini
    elif len(get_equals) == 1:
        return get_equals[0][0]

n = 1
while True:
    M,N = map(int,input().rstrip().split())

    if N == 0 and M == N: break

    edges = []
    K = int(input())

    initial = []
    target = []


    vertex_index = 1

    for k in range(1,K+1):
        i,j = map(int,input().split())
        coordinates[vertex_index] = (i,j)
        initial.append(vertex_index)
        vertex_index += 1

    L = int(input())

    for l in range(0,L):
        i,j = map(int,input().split())
        coordinates[vertex_index] = (i,j)
        target.append(vertex_index)
        vertex_index += 1

    for t in range(1,len(target)):
        for t2 in range(1,len(target)):

            cord_1 = coordinates[t]
            cord_2 = coordinates[t2]

            dist = distance(t,t2)
            edges.append((t,t2,dist))
            edges.append((t2,t,dist))


    # print(edges)
    possibles_path = {}

    for init in initial:
        for t in target:
            # print("init %d target %d"% (init,t))
            edges.append((init,t,distance(t,init)))
            edges.append((t,init,distance(t,init)))
            cost,path = dijkstra(t,init,distance(t,init))
            # print("cost %d ", cost)
            if t not in possibles_path:
                possibles_path[t] = []
                possibles_path[t].append((init, cost))
            else:
                possibles_path[t].append((init, cost))

    # print(possibles_path)
    print("Instancia %d" % n)
    n += 1
    for t in target:
        minor = get_minor(possibles_path[t])
        print("%d %d" % ( coordinates[minor][0], coordinates[minor][1]))

    print()

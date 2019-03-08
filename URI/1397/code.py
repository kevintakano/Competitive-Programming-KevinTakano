while True:

    n = int(input())
    if n == 0: break
    pa = pb = 0
    for x in range(0,n):
        a,b = map(int,input().rstrip().split())
        if a > b:
            pa += 1
        elif a < b:
            pb += 1

    print("%d %d" % (pa,pb))


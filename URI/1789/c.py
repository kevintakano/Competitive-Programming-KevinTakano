import sys


for line in sys.stdin:

    a = int(line)

    velocities = map(int,input().split())

    v = max(velocities)

    if v <= 10:
        print(1)
    elif v < 20:
        print(2)
    else:
        print(3)

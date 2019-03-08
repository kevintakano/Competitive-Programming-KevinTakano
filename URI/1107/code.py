
while True:

    A,C = map(int,input().split())

    if A == 0 and C == 0: break

    slices_square = list(map(int,input().split()))
    height = A

    total = 0

    for i in range(0,C):
        total += max(0,height - slices_square[i])
        height = slices_square[i]

    print(total)


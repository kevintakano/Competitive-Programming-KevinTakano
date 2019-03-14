import sys

for line in sys.stdin:
    N,K = map(int,line.split())

    numbers = list(map(int,input().split())) # get
    numbers = [0] + numbers
    summed = [0] + [ numbers[i] - numbers[i-1] for  i in range(1,N) ]

    summed = sorted(summed,reverse=True)

    k = K - 1
    s = 0
    while(k < N):
        s += summed[k]
        k += 1

    print(s)


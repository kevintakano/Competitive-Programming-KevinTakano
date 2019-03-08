import sys

r = sys.stdin.readline
p = sys.stdout.write

while True:

    B,N = map(int,r().rstrip().split())

    if B == 0 and N == 0: break

    bank_credits = list(map(int,r().rstrip().split()))

    for n in range(0,N):
        d,c,deb = map(int,r().rstrip().split())

        bank_credits[d-1] -= deb
        bank_credits[c-1] += deb

    res = all(cred >= 0 for cred in bank_credits)

    res = 'S' if res == True else 'N'

    p(res + '\n')


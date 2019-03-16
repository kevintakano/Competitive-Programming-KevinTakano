import sys
import string
import functools

alpha = string.ascii_letters[:26]

n = int(input())

def compare(a,b):
    if a[1] != b[1]:
        return int(a[1]) if (a[1] > b[1]) else int(b[1])
    else:
        return ord(a[0]) if (a[0] > b[0]) else ord(b[0])

for k in range(0,n):
    line = input()
    line = line.rstrip()
    ls = list(line)

    d = { a : 0 for a in alpha}

    for c in line:
        c = c.lower()
        if c in alpha:
            d[c] =  d[c] + 1

    ordered = sorted(list(d.items()),key=lambda x: [x[1],-ord(x[0])],reverse=True)

    freq = ordered[0]
    res = []

    for c in ordered:
        if c[1] == freq[1]:
            res.append(c[0])
        else:
            break
    print("".join(res))

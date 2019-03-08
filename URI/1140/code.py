import sys

r = sys.stdin.readline
p = sys.stdout.write

for line in sys.stdin:
    line = line.rstrip()
    if line == '*': break

    words = line.lower().split()

    # jprint(words)
    # print(words[0])

    letter = words[0][0] if len(words[0]) >= 1 else None

    res = all(el[0]==words[0][0] for el in words)

    out = 'Y' if res == True else 'N'

    p(out + '\n')


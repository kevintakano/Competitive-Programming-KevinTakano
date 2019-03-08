import sys

i = 0

ls = []
for line in sys.stdin:
    if i % 2 != 0:
        point = int(line.rstrip())
        ls.append(point)
    i += 1


print("%.1f" % (sum(ls)/len(ls)))

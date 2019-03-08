import sys

i = 0

N = int(input())

cost = []
day = 1
fruits_weight = []
for n in range(0,N*2):
    line = input()
    if i % 2 == 0:
        point = float(line.rstrip())
        cost.append(point)
    else:
        fruits = line.split()
        print("day %d: %d kg" % (day,len(fruits)))
        fruits_weight.append(len(fruits))
        day += 1
    i += 1

print("%.2f kg by day" % (sum(fruits_weight)/len(fruits_weight)))
print("R$ %.2f by day" % (sum(cost)/len(cost)))

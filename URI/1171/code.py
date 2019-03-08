N = int(input())

number_map = {}

for n in range(0,N):
    k = int(input())

    if k in number_map:
        number_map[k] = number_map[k] + 1
    else:
        number_map[k] = 1

ls = sorted(list(number_map))

for el in ls:
    times = number_map[el]
    print("%d aparece %d vez(es)" % (el,times))

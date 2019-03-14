ls = [("tesoura" , "papel"),("papel" ,  "pedra"),("pedra" , "lagarto"),("lagarto" , "spock"),("spock" ,  "tesoura"),("tesoura" , "lagarto"),("lagarto" , "papel"),("papel" , "spock"),("spock" ,  "pedra"),("pedra" ,  "tesoura")]

import itertools

d = {}

for el in ls:
    if el[0] not in d:
        d[el[0]] = [el[1]]
    else:
        d[el[0]].append(el[1])

# print(d)

N = int(input())

for n in range(0,N):
    a,b = input().split()

    a = a.lower()
    b = b.lower()
    winner_a = d[a]
    winner_b = d[b]

   # print("o %s %s" % (a,b))
   # print("w %s %s" % (winner_a,winner_b))
    print("Caso #%d:" %(n+1),end='')
    if b in winner_a:
        print(" Bazinga!")
    elif a in winner_b:
        print(" Raj trapaceou!")
    else:
        print(" De novo!")


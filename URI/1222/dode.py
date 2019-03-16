import sys
from math import *


for line in sys.stdin:
    n,l,c = map(int,line.split())

    t = input().split()

    lent = len(t)
    lines = 0
    i = 0
    words = ""
    spaces = ''
    while( i < lent ):
        if words == '':
            spaces = ''
        else:
            spaces = ' '

        if len(words + spaces + t[i]) <= c:
            words += spaces + t[i]
        else:
            lines += 1
           #  print(words + " len = " + str(len(words)))
            words = t[i]

        i += 1
    if words != "":
       #  print(words + " len = " + str(len(words)))
        lines += 1


    #  print(lines)

    print(ceil(lines/l))

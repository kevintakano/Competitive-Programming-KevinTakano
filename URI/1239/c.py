import sys

for line in sys.stdin:
    line = line.rstrip()
    ls = list(line)

    d = { '_' : 0 , '*':  0 }

    for i in range(0,len(line)):
        if ls[i] == '_':
            if d['_'] % 2 == 0:
                d['_'] += 1
                ls[i] ='<i>'
            else:
                d['_'] += 1
                ls[i] ='</i>'

        if ls[i] == '*':
            if d['*'] % 2 == 0:
                d['*'] += 1
                ls[i] ='<b>'
            else:
                d['*'] += 1
                ls[i] ='</b>'


    print("".join(ls))

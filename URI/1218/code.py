import sys

p = sys.stdout.write

n = 0
i = 0
k = 0
for line in sys.stdin:
    if i % 2 == 0:
        n = int(line.rstrip())
    else:
        shoes = line.rstrip().split()
        it = iter(shoes)
        shoes = list(zip(it,it))
        shoes_filtered = list(filter(lambda a: int(a[0]) == n,shoes))

        equals_pairs = len(shoes_filtered)
        f_pairs = len(list(filter(lambda a: a[1] == 'F',shoes_filtered)))
        m_pairs = len(list(filter(lambda a: a[1] == 'M',shoes_filtered)))
        if(k != 0):
            print()
        print('Caso %d:' % (k+1))
        print('Pares Iguais: %d' % (equals_pairs))
        print('F: %d' % (f_pairs))
        print('M: %d' % (m_pairs))

        k += 1
    i += 1

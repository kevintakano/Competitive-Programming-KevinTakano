import string
import sys
import logging

logging.basicConfig(level=logging.INFO)
alpha = string.ascii_lowercase + string.ascii_uppercase + '.'
l = logging.debug

def hasJustOnePointOccurrence(word):
    occurrences = 0
    for c in word:
        if c == '.':
            occurrences += 1

        if occurrences > 1:
            return False

    return occurrences == 1
def is_a_word(simb):

    isInAlpha = True
    for c in simb:
        if c not in alpha:
            isInAlpha = False
            break

    hasOnlyLastPoint = False

    if(simb[len(simb)-1] == '.' and hasJustOnePointOccurrence(simb) == True):
        hasOnlyLastPoint = True

    if isInAlpha == True and hasOnlyLastPoint == True and '.' in simb and len(simb) > 1:
        return True
    elif isInAlpha == True and '.' not in simb:
        return True
    else:
        return False

def solve(simbols):
    logging.debug("simbols" + str(simbols))
    rl = []
    for simb in simbols:
        if is_a_word(simb) == True:
            rl.append(simb)

    filtered = logging.debug("filtered " + str(rl))

    if len(rl) == 0:
        return 0
    else:
        nested = "".join(rl).replace('.','')
        total = len("".join(nested))

        return total//(len(rl))

for line in sys.stdin:

    simbols = line.split()

    total = solve(simbols)

    res = 0

    l("total = " + str(total))

    if total <= 3:
        res = 250
    elif total <= 5:
        res = 500
    else:
        res = 1000

    sys.stdout.write(str(res) + "\n")

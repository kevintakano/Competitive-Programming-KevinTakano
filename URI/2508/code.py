import string
import sys

table = {}
alphabet  = string.ascii_lowercase

iteration = 0
for a in alphabet:
    table[a] = iteration % 9 + 1
    iteration += 1


def lucky_number(number):

    str_number = str(number)

    if len(str_number) == 1:
        return number

    else:

        list_number = list(str_number)

        int_ls = map(int,list_number)

        return lucky_number(sum(int_ls))


# print(list(table.values()))

for line in sys.stdin:
    name = line
    char_list =  sum([ list(na.lower()) for na in name.split() ],[])

    numbers = sum([ table[c]  for c in char_list ])

    # print(numbers)

    print(lucky_number(numbers))

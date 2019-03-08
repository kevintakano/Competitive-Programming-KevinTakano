
def next(direction,command):
    if direction == 'N' and command == 'D':
        return 'L'
    elif direction == 'N' and command == 'E':
        return 'O'
    if direction == 'L' and command == 'D':
        return 'S'
    elif direction == 'L' and command == 'E':
        return 'N'
    if direction == 'S' and command == 'D':
        return 'O'
    elif direction == 'S' and command == 'E':
        return 'L'
    if direction == 'O' and command == 'D':
        return 'N'
    elif direction == 'O' and command == 'E':
        return 'S'



while True:
    n = int(input())

    if n == 0: break

    commands = input().rstrip()

    next_dir = 'N'
    for c in commands:
        next_dir = next(next_dir,c)

    print(next_dir)



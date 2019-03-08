
index_orientation = {'N' : 0, 'L' : 1, 'S' : 2, 'O' : 3}

reverse_index_orientation = "NLSO"
dx = [-1,0,+1,0]
dy = [0,+1,0,-1]

while True:
    N,M,S = map(int,input().split())

    if N == 0 and M == 0: break
    count = 0
    grid = [None for i in range(0,N)]

    for i in range(0,N):
        grid[i] = list(input().rstrip())

    sequences = input()

    cur_orientation = 0
    x = 0
    y = 0

    def get_pos():
        global cur_orientation, x, y
        for i in range(0,N):
            for j in range(0,M):
                if grid[i][j] in "NSLO":
                    x = i
                    y = j
                    cur_orientation = index_orientation[grid[i][j]]
                    break

    def valid(px,py):
        return px >= 0 and px < N and py >= 0 and py < M

    def count_pilastra():
        global x,y, count
        global grid
        if grid[x][y] == '*':
            grid[x][y] = "."
            count += 1

    def move():
        global x,y

        next_x = x + dx[ cur_orientation  ]
        next_y = y + dy[ cur_orientation  ]

        if valid(next_x,next_y) and grid[next_x][next_y] != '#':
            x = next_x
            y = next_y
            count_pilastra()

    def change_dir(s):
        global cur_orientation
        if s == 'D':
            cur_orientation = (cur_orientation + 1 ) % 4
        else:
            cur_orientation = (cur_orientation - 1 ) % 4


    def command(s):
        if s == 'F':
            move()
        else:
            change_dir(s)

    get_pos()
    for s in sequences:
        command(s)

    print(count)

# https://www.acmicpc.net/problem/12100
# 2048 (easy)

import copy
n_n_board = int(input())
if n_n_board == 1: print(input()); exit()
game_board = [[[0,0] for i in range(n_n_board)] for _ in range(n_n_board)]
for n in range(n_n_board):
    row = list(map(int,input().split(" ")))
    for i in range(n_n_board):
        game_board[n][i][0] = row[i]

maxval = 0

def move(game_board, count, dir_idx):
    global maxval
    board = copy.deepcopy(game_board)
    
    # 보드 visited 초기화
    for y in range(n_n_board):
        for x in range(n_n_board):
            board[y][x][1] = 0

    # 각 방향으로 민다
    # up
    if dir_idx == 0:
        for i in range(1,n_n_board):
            for j in range(n_n_board):
                y, x = i, j
                while(y>0):
                    if board[y-1][x][0] == 0: # 위 칸이 0일경우 치환
                        board[y-1][x] = board[y][x]
                        board[y][x] = [0,0]
                        y -= 1
                    elif board[y-1][x][0] == board[y][x][0] and board[y-1][x][1] == 0: # 숫자가 같으면서 not visited면 합치기
                        board[y-1][x] = [board[y-1][x][0]*2, 1]
                        board[y][x] = [0,0]
                        break
                    else: break # 나머지 경우는 숫자가 다르거나 visited인 경우이므로 현재 자리에 멈춤
    
    # down
    elif dir_idx == 1:
        for i in range(n_n_board-2, -1, -1):
            for j in range(n_n_board):
                y, x = i, j
                while(y<n_n_board-1):
                    if board[y+1][x][0] == 0: # 아래 칸이 0일경우 치환
                        board[y+1][x] = board[y][x]
                        board[y][x] = [0,0]
                        y += 1
                    elif board[y+1][x][0] == board[y][x][0] and board[y+1][x][1] == 0: # 숫자가 같으면서 not visited면 합치기
                        board[y+1][x] = [board[y+1][x][0]*2, 1]
                        board[y][x] = [0,0]
                        break
                    else: break # 나머지 경우는 숫자가 다르거나 visited인 경우이므로 현재 자리에 멈춤
    
    # left
    elif dir_idx == 2:
        for i in range(n_n_board):
            for j in range(1, n_n_board):
                y, x = i, j
                while(x>0):
                    if board[y][x-1][0] == 0: # 왼쪽 칸이 0일경우 치환
                        board[y][x-1] = board[y][x]
                        board[y][x] = [0,0]
                        x -= 1
                    elif board[y][x-1][0] == board[y][x][0] and board[y][x-1][1] == 0: # 숫자가 같으면서 not visited면 합치기
                        board[y][x-1] = [board[y][x-1][0]*2, 1]
                        board[y][x] = [0,0]
                        break
                    else: break # 나머지 경우는 숫자가 다르거나 visited인 경우이므로 현재 자리에 멈춤

    # right
    else:
        for i in range(n_n_board):
            for j in range(n_n_board-2, -1, -1):
                y, x = i, j
                while(x<n_n_board-1):
                    if board[y][x+1][0] == 0: # 오른쪽 칸이 0일경우 치환
                        board[y][x+1] = board[y][x]
                        board[y][x] = [0,0]
                        x += 1
                    elif board[y][x+1][0] == board[y][x][0] and board[y][x+1][1] == 0: # 숫자가 같으면서 not visited면 합치기
                        board[y][x+1] = [board[y][x+1][0]*2, 1]
                        board[y][x] = [0,0]
                        break
                    else: break # 나머지 경우는 숫자가 다르거나 visited인 경우이므로 현재 자리에 멈춤
        
    if count == 5:
        for y in range(n_n_board):
            for x in range(n_n_board):
                if board[y][x][0] > maxval: maxval = board[y][x][0]
        return
    else: 
        for dir in range(4): move(board, count+1, dir)

for dir in range(4): move(game_board, 1, dir)
print(maxval)
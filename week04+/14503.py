# https://www.acmicpc.net/problem/14503
# 로봇 청소기

vertical, horizontal = map(int, input().split(" "))
directions = [[-1,0],[0,1],[1,0],[0,-1]]
y,x,d = map(int, input().split(" "))
y+=1;x+=1
count = 0

roomMap = [[1 for _ in range(horizontal+2)]]
for v in range(vertical):
    row = [1]
    row.extend(list(map(int,input().strip().split(" "))))
    row.append(1)
    roomMap.append(row)
roomMap.append([1 for _ in range(horizontal+2)])

while(True):
    if roomMap[y][x] == 1: print(count); exit()
    if roomMap[y][x] == 0: roomMap[y][x] = -1; count += 1
    way = False
    for i in range(4):
        d = (d+3)%4
        if roomMap[y+directions[d][0]][x+directions[d][1]] == 0:
            way = True
            y += directions[d][0]
            x += directions[d][1]
            break
    if not way:
        y -= directions[d][0]
        x -= directions[d][1]
# https://www.acmicpc.net/problem/4179
# 불!

# 문제
# 지훈이는 미로에서 일을 한다. 지훈이를 미로에서 탈출하도록 도와주자!
# 미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부, 그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.
# 지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다) 이동한다.
# 불은 각 지점에서 네 방향으로 확산된다.
# 지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.
# 지훈이와 불은 벽이 있는 공간은 통과하지 못한다.

# 입력
# 입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1000 이다. R은 미로 행의 개수, C는 열의 개수이다.
# 다음 입력으로 R줄동안 각각의 미로 행이 주어진다.
# 각각의 문자들은 다음을 뜻한다.

# #: 벽
# .: 지나갈 수 있는 공간
# J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
# F: 불이 난 공간
# J는 입력에서 하나만 주어진다.

# 출력
# 지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는 경우 IMPOSSIBLE 을 출력한다.
# 지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다.

# 예제 입력 1 
# 4 4
# ####
# #JF#
# #..#
# #..#
# 예제 출력 1 
# 3

import sys
from collections import deque
input = sys.stdin.readline

directions = [[1,0],[-1,0],[0,-1],[0,1]]
vertical, horizontal = map(int, input().split())
mazeMap = []
jq = deque()
fq = deque()
for v in range(vertical):
    mazeMap.append(list(input().strip()))
    for h in range(horizontal):
        if mazeMap[v][h] == "J": jq.append([v,h,0])
        if mazeMap[v][h] == "F": fq.append([v,h,0])
if jq[0][0] == 0 or jq[0][0] == vertical-1 or jq[0][1] == 0 or jq[0][1] == horizontal-1: print(1); exit()

count = 0
while(jq):
    while(fq and fq[0][2] == count):
        cord = fq.popleft()
        for d in range(4):
            newy = cord[0] + directions[d][0]
            newx = cord[1] + directions[d][1]
            if newy < 0 or newy >= vertical or newx < 0 or newx >= horizontal: continue
            if mazeMap[newy][newx] == ".":
                fq.append([newy, newx, count+1])
                mazeMap[newy][newx] = "#"

    while(jq and jq[0][2] == count):
        cord = jq.popleft()
        for d in range(4):
            newy = cord[0] + directions[d][0]
            newx = cord[1] + directions[d][1]
            if mazeMap[newy][newx] == ".":
                if newy == 0 or newy == vertical-1 or newx == 0 or newx == horizontal-1: print(count+2); exit()
                jq.append([newy, newx, count+1])
                mazeMap[newy][newx] = "#"
    count += 1

print("IMPOSSIBLE")
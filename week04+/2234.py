# https://www.acmicpc.net/problem/2234
# 성곽

# 문제
# 대략 위의 그림과 같이 생긴 성곽이 있다. 굵은 선은 벽을 나타내고, 점선은 벽이 없어서 지나다닐 수 있는 통로를 나타낸다.
# 이러한 형태의 성의 지도를 입력받아서 다음을 계산하는 프로그램을 작성하시오.
# 이 성에 있는 방의 개수
# 가장 넓은 방의 넓이
# 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
# 위의 예에서는 방은 5개고, 가장 큰 방은 9개의 칸으로 이루어져 있으며,
# 위의 그림에서 화살표가 가리키는 벽을 제거하면 16인 크기의 방을 얻을 수 있다.
# 성은 M × N(1 ≤ M, N ≤ 50)개의 정사각형 칸으로 이루어진다.
# 성에는 최소 두 개의 방이 있어서, 항상 하나의 벽을 제거하여 두 방을 합치는 경우가 있다.

# 입력
# 첫째 줄에 두 정수 N, M이 주어진다. 다음 M개의 줄에는 N개의 정수로 벽에 대한 정보가 주어진다.
# 벽에 대한 정보는 한 정수로 주어지는데, 서쪽에 벽이 있을 때는 1을, 북쪽에 벽이 있을 때는 2를, 동쪽에 벽이 있을 때는 4를, 남쪽에 벽이 있을 때는 8을 더한 값이 주어진다.
# 참고로 이진수의 각 비트를 생각하면 쉽다. 따라서 이 값은 0부터 15까지의 범위 안에 있다.

# 출력
# 첫째 줄에 1의 답을, 둘째 줄에 2의 답을, 셋째 줄에 3의 답을 출력한다.

# 예제 입력 1 
# 7 4
# 11 6 11 6 3 10 6
# 7 9 6 13 5 15 5
# 1 10 12 7 13 7 5
# 13 11 10 8 10 12 13
# 예제 출력 1 
# 5
# 9
# 16

from collections import deque
n,m = map(int,input().split(" "))
cmap = []
for _ in range(m):
    cmap.append(list(map(int, input().split(" "))))
curr = 0
rmap = [[-1 for _ in range(n)] for _ in range(m)]
q = deque()
for i in range(m):
    for j in range(n):
        if rmap[i][j] != -1: continue
        q.append([i, j])
        rmap[i][j] = curr
        while (q):
            cord = q.popleft()
            if (cmap[cord[0]][cord[1]] & 1) == False: # 서쪽에 벽이 없음
                if rmap[cord[0]][cord[1]-1] == -1:
                    rmap[cord[0]][cord[1]-1] = curr
                    q.append([cord[0], cord[1]-1])
            if (cmap[cord[0]][cord[1]] & 2) == False: # 북쪽에 벽이 없음
                if rmap[cord[0]-1][cord[1]] == -1:
                    rmap[cord[0]-1][cord[1]] = curr
                    q.append([cord[0]-1, cord[1]])
            if (cmap[cord[0]][cord[1]] & 4) == False: # 동쪽에 벽이 없음
                if rmap[cord[0]][cord[1]+1] == -1:
                    rmap[cord[0]][cord[1]+1] = curr
                    q.append([cord[0], cord[1]+1])
            if (cmap[cord[0]][cord[1]] & 8) == False: # 남쪽에 벽이 없음
                if rmap[cord[0]+1][cord[1]] == -1:
                    rmap[cord[0]+1][cord[1]] = curr
                    q.append([cord[0]+1, cord[1]])
        curr += 1
roomtable = [0 for _ in range(curr)]
linkset = set()
for i in range(m):
    for j in range(n):
        a = rmap[i][j]
        roomtable[a] += 1
        if i < m-1: 
            b = rmap[i+1][j]
            if a<b: linkset.add((a,b))
            elif a>b: linkset.add((b,a))
        if j < n-1:
            b = rmap[i][j+1]
            if a<b: linkset.add((a,b))
            elif a>b: linkset.add((b,a))
maxval = 0
for entry in linkset:
    if maxval < roomtable[entry[0]] + roomtable[entry[1]]:
        maxval = roomtable[entry[0]] + roomtable[entry[1]]
print(curr)
print(max(roomtable))
print(maxval)
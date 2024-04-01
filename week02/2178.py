## https://www.acmicpc.net/problem/2178
## 미로 탐색

# 문제
# N×M크기의 배열로 표현되는 미로가 있다.
# 1	0	1	1	1	1
# 1	0	1	0	1	0
# 1	0	1	0	1	1
# 1	1	1	0	1	1
# 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.
# 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
# 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
# 위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

# 입력
# 첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다.
# 각각의 수들은 붙어서 입력으로 주어진다.

# 출력
# 첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

# 예제 입력 1 
# 4 6
# 101111
# 101010
# 101011
# 111011

# 예제 출력 1 
# 15

first_line = input().split(" ")
horizontal = int(first_line[1])
vertical = int(first_line[0])
map = []
candidate_list = [[0,0]]
visited_map = []
# map[i][j] 그리기
for j in range(vertical):
    row = list(input())
    visited_row = []
    for i in range(horizontal):
        row[i] = int(row[i])
        visited_row.append(0)
    map.append(row)
    visited_map.append(visited_row)

# 현재 좌표 상하좌우에 방문안한 1 있는지 확인해서 후보리스트에 넣기
def seek_and_enque(j, i):
    if (j-1) >= 0 and (visited_map[j-1][i] != 1):
        if map[j-1][i] :
            map[j-1][i] = map[j][i] +1
            candidate_list.append([j-1, i])
            visited_map[j-1][i] = 1
    if (i-1) >= 0 and (visited_map[j][i-1] != 1):
        if map[j][i-1] :
            map[j][i-1] = map[j][i] +1
            candidate_list.append([j, i-1])
            visited_map[j][i-1] = 1
    if (j+1) < vertical and (visited_map[j+1][i] != 1):
        if map[j+1][i] :
            map[j+1][i] = map[j][i] +1
            candidate_list.append([j+1, i])
            visited_map[j+1][i] = 1
    if (i+1) < horizontal and (visited_map[j][i+1] != 1):
        if map[j][i+1] :
            map[j][i+1] = map[j][i] +1
            candidate_list.append([j, i+1])
            visited_map[j][i+1] = 1

# 후보리스트에서 좌표 하나 디큐 해보고 해당 좌표 기준 seek and enque.
# 팝된 좌표가 종착지면 프린트
while True:
    cord = candidate_list.pop(0)
    if cord == [vertical-1, horizontal-1]:
        print(map[vertical -1][horizontal -1])
        break
    else:
        seek_and_enque(cord[0],cord[1])
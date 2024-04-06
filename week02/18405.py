## https://www.acmicpc.net/problem/18405
## 경쟁적 전염

# NxN 크기의 시험관이 있다. 시험관은 1x1 크기의 칸으로 나누어지며, 특정한 위치에는 바이러스가 존재할 수 있다.
# 모든 바이러스는 1번부터 K번까지의 바이러스 종류 중 하나에 속한다.
# 시험관에 존재하는 모든 바이러스는 1초마다 상, 하, 좌, 우의 방향으로 증식해 나간다.
# 단, 매 초마다 번호가 낮은 종류의 바이러스부터 먼저 증식한다.
# 또한 증식 과정에서 특정한 칸에 이미 어떠한 바이러스가 존재한다면, 그 곳에는 다른 바이러스가 들어갈 수 없다.
# 시험관의 크기와 바이러스의 위치 정보가 주어졌을 때,
# S초가 지난 후에 (X,Y)에 존재하는 바이러스의 종류를 출력하는 프로그램을 작성하시오.
# 만약 S초가 지난 후에 해당 위치에 바이러스가 존재하지 않는다면, 0을 출력한다.
# 이 때 X와 Y는 각각 행과 열의 위치를 의미하며, 시험관의 가장 왼쪽 위에 해당하는 곳은 (1,1)에 해당한다.

# 입력
# 첫째 줄에 자연수 N, K가 공백을 기준으로 구분되어 주어진다. (1 ≤ N ≤ 200, 1 ≤ K ≤ 1,000)
# 둘째 줄부터 N개의 줄에 걸쳐서 시험관의 정보가 주어진다.
# 각 행은 N개의 원소로 구성되며, 해당 위치에 존재하는 바이러스의 번호가 공백을 기준으로 구분되어 주어진다.
# 단, 해당 위치에 바이러스가 존재하지 않는 경우 0이 주어진다. 또한 모든 바이러스의 번호는 K이하의 자연수로만 주어진다.
# N+2번째 줄에는 S, X, Y가 공백을 기준으로 구분되어 주어진다. (0 ≤ S ≤ 10,000, 1 ≤ X, Y ≤ N)

# 출력
# S초 뒤에 (X,Y)에 존재하는 바이러스의 종류를 출력한다.
# 만약 S초 뒤에 해당 위치에 바이러스가 존재하지 않는다면, 0을 출력한다.

# 예제 입력 1 
# 3 3
# 1 0 2
# 0 0 0
# 3 0 0
# 2 3 2

# 예제 출력 1 
# 3

# 전략: 바이러스를 움직이는게 아니라 타겟 x,y에서 시간 스텝으로 십자형태로 검출범위를 늘려가며
#       가장 가까운 바이러스를 탐색.

first_input = input().split(" ")
n_square = int(first_input[0])
k_of_virus = int(first_input[1])

# 두번째 n개의 인풋으로 맵을 그린다. map[y][x]좌표 형태로 표현.
map = []
for _ in range(n_square):
    input_row = input().split(" ")
    row = []
    for i in input_row:
        row.append(int(i))
    map.append(row)

# 마지막 인풋은 우리가 보려고 하는 타겟 지점과 시간
# 맵이 0 ~ n-1 좌표로 되어있기 때문에 1씩 빼줌 
third_input = input().split(" ")
s = int(third_input[0])
target_y = int(third_input[1]) - 1
target_x = int(third_input[2]) - 1

# 검출할 큐에 타겟 지점 세팅. 처음부터 바이러스가 있으면 바로 프린트하고 exit.
# 잘하면 while문에 넣어서 좀 깔끔하게 만들수 있을지도?
que = [[] for _ in range(s+1)]
que[0].append([target_y, target_x])
if map[target_y][target_x] > 0:
    print(map[target_y][target_x])
    exit()
map[target_y][target_x] = -1 # 시작위치 visited 설정. visited는 맵에 -1로 표시한다.
detected = [] # 검출된 바이러스를 담는 통

for time in range(s): # 타겟으로부터 time = 0부터 s시간 십자범위동안 탐색
    while que[time]: # 현재 타임의 큐가 다 떨어질때까지
        cord = que[time].pop(0)
        x = cord[1]
        y = cord[0]
        # 상하좌우 확인
        # 방향으로 설정해서 for문으로 돌리자
        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        for direction in directions: # 상하좌우에 대해서
            i = x + direction[1]
            j = y + direction[0]
            if (0 <= i < n_square) and (0 <= j < n_square): # 맵 범위를 넘지 않도록
                if map[j][i] == -1: continue # visited면 넘기고
                elif map[j][i] == 0: # 0이면 다음 타임 큐에 예약
                    map[j][i] = -1 # 큐에 중복으로 들어가지 않기위해 선제적으로 visitied 표시
                    que[time + 1].append([j, i])
                else: detected.append(map[j][i]) # visited도 아니고 0도 아니면 바이러스 포착!

    if detected != []: # 한 타임 끝나고 검출된 바이러스 있으면 그 중에서 가장 낮은 수 출력
        print(sorted(detected)[0])
        break
if detected == []: print(0) # 모든 시간동안 검출이 안된다면 0 출력
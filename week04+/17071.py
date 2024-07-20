# https://www.acmicpc.net/problem/17071
# 숨바꼭질 5

# 문제
# 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 500,000)에 있고, 동생은 점 K(0 ≤ K ≤ 500,000)에 있다.
# 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
# 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
# 동생은 항상 걷기만 한다. 동생은 항상 매 초마다 이동을 하며, 이동은 가속이 붙는다.
# 동생이 이동하는 거리는 이전에 이동한 거리보다 1을 더한 만큼 이동한다.
# 즉, 동생의 처음 위치는 K, 1초가 지난 후 위치는 K+1, 2초가 지난 후 위치는 K+1+2, 3초가 지난 후의 위치는 K+1+2+3이다.
# 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
# 동생을 찾는 위치는 정수 좌표이어야 하고, 수빈이가 0보다 작은 좌표로, 50만보다 큰 좌표로 이동하는 것은 불가능하다.

# 입력
# 첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

# 출력
# 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다. 수빈이가 동생을 찾을 수 없거나, 찾는 위치가 500,000을 넘는 경우에는 -1을 출력한다.

# 예제 입력 1 
# 5 17
# 예제 출력 1 
# 2
# 예제 입력 2 
# 17 5
# 예제 출력 2 
# 4
# 예제 입력 3 
# 6 6
# 예제 출력 3 
# 0
# 예제 입력 4 
# 1 500000
# 예제 출력 4 
# -1

n, k = map(int, input().split(" "))
if k == n:
    print(0)
    exit()

# visited는 몇번중에 몇번만에 가는지
visited = [[0,0]*500001]
willvisit = []
count = 0
chance = 0

def checkNmark(target, idx):
    if visited[target][1] == 0:
        visited[target][0] = count
        visited[target][1] += visited[idx][1]
        willvisit.append(target)
    elif visited[target][0] == count:
        visited[target][1] += visited[idx][1]

if n==0: visited[k][0] = 1; n = 1
else: visited[k][0] = 0 
visited[k][1] = 1

# 동생의 위치가 50만을 넘기 전까지 chance == count인 경우를 탐색
while k <= 500000:
    willvisit.append(k)
    
    while len(willvisit) > 0:
        idx = willvisit.pop(0)
        if idx > k+1: continue

        count = visited[idx][0]+1

        if idx%2 == 0: checkNmark(idx//2, idx)
        checkNmark(idx+1,idx)
        checkNmark(idx-1,idx)

        if visited[n][0] < count and visited[n][1] !=0:
            print(visited[n][0])
            # print(visited[n][1])
            exit()


    chance += 1
    k += chance

# https://www.acmicpc.net/problem/28069
# 김밥천국의 계단

# 문제
# 민희는 미니김밥이 유명한 천국에 가려고 합니다.
# 천국 문 앞에는 무한히 많은 계단이 있고 가장 아래 계단의 번호가 0번이며, 위로 올라가면서 순서대로 번호가 붙어있습니다.
# 그중 N번째 계단 옆에 김밥 가게가 있습니다.
# 민희는 매번 다음의 2가지 행동 중 하나를 선택해서 총 K번 행동할 수 있으며, 정확히 K번째 행동에서 N번째 계단에 도달하면 미니김밥을 먹을 수 있습니다.
# 계단 한 칸을 올라갑니다.
# 민희가 집에서 가지고 온 지팡이를 계단에 두드립니다. 만약 민희가 
# $i$ 번째 계단에서 지팡이를 두드리면 
# $i +\left \lfloor \cfrac{i}{2} \right \rfloor$번째 계단으로 순간이동합니다.
# 현재 민희는 0번째 계단에 있습니다. 민희가 미니김밥을 먹을 수 있을지 구해 봅시다.

# 입력
# 첫 번째 줄에 계단 개수에 해당하는 N, 계단을 오르는 횟수 K가 주어진다. 
# (1 \leq N, K \leq 1\,000\,000)

# 출력
# 민희가 N개의 계단을 K번 만에 올라 미니김밥을 먹을 수 있으면 minigimbob을, 그러지 못해 물만 마신다면 water을 출력한다.

# 예제 입력 1 
# 5 2
# 예제 출력 1 
# water
# 예제 입력 2 
# 42 10
# 예제 출력 2 
# minigimbob

n, k = map(int, input().split(" "))
if n<4:
    dptable = [0,1,2,3]
    if dptable[n] <= k: print("minigimbob")
    else: print("water")
    exit()

dptable = [0 for _ in range(n+1)]
dptable[1] = 1
dptable[2] = 2
dptable[3] = 3
for i in range(2, n):
    onePointFive = i + i//2
    if onePointFive == n and dptable[i] < k: print("minigimbob"); exit()
    if onePointFive < n: dptable[onePointFive] = dptable[i]+1
    if dptable[i+1] == 0: dptable[i+1] = dptable[i]+1

if dptable[n] <= k: print("minigimbob")
else: print("water")
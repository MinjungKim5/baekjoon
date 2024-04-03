## https://www.acmicpc.net/problem/2617
## 구슬 찾기

# 문제
# 모양은 같으나, 무게가 모두 다른 N개의 구슬이 있다. N은 홀수이며, 구슬에는 번호가 1,2,...,N으로 붙어 있다.
# 이 구슬 중에서 무게가 전체의 중간인 (무게 순서로 (N+1)/2번째) 구슬을 찾기 위해서 아래와 같은 일을 하려 한다.
# 우리에게 주어진 것은 양팔 저울이다. 한 쌍의 구슬을 골라서 양팔 저울의 양쪽에 하나씩 올려 보면
# 어느 쪽이 무거운가를 알 수 있다. 이렇게 M개의 쌍을 골라서 각각 양팔 저울에 올려서 어느 것이 무거운가를 모두 알아냈다.
# 이 결과를 이용하여 무게가 중간이 될 가능성이 전혀 없는 구슬들은 먼저 제외한다.

# 예를 들어, N=5이고, M=4 쌍의 구슬에 대해서 어느 쪽이 무거운가를 알아낸 결과가 아래에 있다.

# 구슬 2번이 구슬 1번보다 무겁다.
# 구슬 4번이 구슬 3번보다 무겁다.
# 구슬 5번이 구슬 1번보다 무겁다.
# 구슬 4번이 구슬 2번보다 무겁다.
# 위와 같이 네 개의 결과만을 알고 있으면, 무게가 중간인 구슬을 정확하게 찾을 수는 없지만,
# 1번 구슬과 4번 구슬은 무게가 중간인 구슬이 절대 될 수 없다는 것은 확실히 알 수 있다.
# 1번 구슬보다 무거운 것이 2, 4, 5번 구슬이고, 4번 보다 가벼운 것이 1, 2, 3번이다. 따라서 답은 2개이다.

# M 개의 쌍에 대한 결과를 보고 무게가 중간인 구슬이 될 수 없는 구슬의 개수를 구하는 프로그램을 작성하시오.

# 입력
# 첫 줄은 구슬의 개수를 나타내는 정수 N(1 ≤ N ≤ 99)과 저울에 올려 본 쌍의 개수 M(1 ≤ M ≤ N(N-1)/2)이 주어진다.
# 그 다음 M 개의 줄은 각 줄마다 두 개의 구슬 번호가 주어지는데, 앞 번호의 구슬이 뒤 번호의 구슬보다 무겁다는 것을 뜻한다.

# 출력
# 첫 줄에 무게가 중간이 절대로 될 수 없는 구슬의 수를 출력 한다.

# 예제 입력 1 
# 5 4
# 2 1
# 4 3
# 5 1
# 4 2

# 예제 출력 1 
# 2

import math

first_input = input().split(" ")
n_of_beads = int(first_input[0])
m_of_compares = int(first_input[1])

adj_matrix = []
for i in range(n_of_beads):
    adj_row = []
    for _ in range(n_of_beads):
        adj_row.append(math.inf)
    adj_row[i] = 0
    adj_matrix.append(adj_row)

for _ in range(m_of_compares):
    edge = input().split(" ")
    bead_from = int(edge[0]) - 1
    bead_to = int(edge[1]) - 1
    adj_matrix[bead_from][bead_to] = 1

# print(adj_matrix)

def fl_wa(adj_matrix):
    # cost_map = []
    # for i in range(n_of_beads):
    #     cost_row = []
    #     for _ in range(n_of_beads):
    #         cost_row.append(math.inf)
    #     cost_row[i] = 0
    #     cost_map.append(cost_row)

    for via in range(n_of_beads):
        for start in range(n_of_beads):
            for end in range(n_of_beads):
                if adj_matrix[start][end] > adj_matrix[start][via] + adj_matrix[via][end]:
                    adj_matrix[start][end] = adj_matrix[start][via] + adj_matrix[via][end]

    return adj_matrix

dist_map = fl_wa(adj_matrix)
# print(dist_map)
lighter = []
heavier = []
for _ in range(n_of_beads):
    lighter.append(0)
    heavier.append(0)
for from_bead in range(n_of_beads):
    for to_bead in range(n_of_beads):
        if dist_map[from_bead][to_bead] != math.inf and dist_map[from_bead][to_bead] != 0:
            lighter[from_bead] += 1
            heavier[to_bead] += 1
count = 0
for i in range(n_of_beads):
    if lighter[i] > n_of_beads/2 or heavier[i] > n_of_beads/2:
        count +=1
print(count)

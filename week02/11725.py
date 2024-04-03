## https://www.acmicpc.net/problem/11725
## 트리의 부모 찾기

# 문제
# 루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

# 입력
# 첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다.
# 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

# 출력
# 첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.

# 예제 입력 1
# 7
# 1 6
# 6 3
# 3 5
# 4 1
# 2 4
# 4 7

# 예제 출력 1
# 4
# 6
# 1
# 3
# 1
# 4

import sys
n_of_nodes = int(sys.stdin.readline())

# parents 정보 초기화
parents = [i for i in range(n_of_nodes)]

# 인접리스트 작성
adj_list = [[] for _ in range(n_of_nodes)]
for i in range(n_of_nodes - 1):
    edge = sys.stdin.readline().split(" ")
    adj_list[int(edge[0]) - 1].append(int(edge[1]) - 1)
    adj_list[int(edge[1]) - 1].append(int(edge[0]) - 1)

# 1부터 BFS로 돌면서 parents 최신화
que = [0]
visited = [0 for _ in range(n_of_nodes)]
visited[0] = 1
while que:
    current = que.pop(0)
    for child in adj_list[current]:
        if visited[child] == 0:
            parents[child] = current
            que.append(child)
            visited[child] = 1
    
for i in range(1, n_of_nodes):
    print(parents[i] + 1)
        


"""
이건 시간초과


# 부모찾기: 루트와 연결되어있는지 확인용
def check_parent(n):
    if n == parents[n]: return n
    my_parent = check_parent(parents[n])
    return my_parent

    
# 엣지정보 큐에 넣기
que = []
for _ in range(n_of_nodes -1):
    edge_input = sys.stdin.readline().split(" ")
    edge = [int(edge_input[0]) - 1, int(edge_input[1]) - 1]
    que.append(edge)    

# 큐에서 하나씩 디큐해서 부모 리스트 최신화
# 루트와 연결되어있는 쪽이 부모임. 둘다 아니면 큐에 다시 넣기. 언젠가는 연결 되겠지...
while que:
    edge = que.pop(0)
    a = check_parent(edge[0])
    b = check_parent(edge[1])
    if a == 0: parents[edge[1]] = edge[0]
    elif b == 0: parents[edge[0]] = edge[1]
    else: que.append(edge)

for i in range(1, n_of_nodes):
    print(parents[i] + 1)
"""
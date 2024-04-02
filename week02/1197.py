## https://www.acmicpc.net/problem/1197
## 최소 스패닝 트리

# 문제
# 그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.
# 최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.

# 입력
# 첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다.
# 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다.
# 이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다.
# C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.
# 그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다.
# 최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.

# 출력
# 첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.

# 예제 입력 1 
# 3 3
# 1 2 1
# 2 3 2
# 1 3 3

# 예제 출력 1 
# 3

# 최초입력으로 V와 E값 획득
first_input = input().split(" ")
n_of_vertex = int(first_input[0])
n_of_edge = int(first_input[1])

# edge정보 입력. V번호는 -1씩 해줘서 배열에 적합하도록 변경
edges = []
for i in range(n_of_edge):
    edge = (input().split(" "))
    edge[0] = int(edge[0]) - 1
    edge[1] = int(edge[1]) - 1
    edge[2] = int(edge[2])
    edges.append(edge)

def third_element_key(item):
    return item[2]

# edges 오름차순 정렬
edges.sort(key=third_element_key)

# parent no(나는 flag라고 하겠음) 배열 생성. 처음에는 각자 자기 V번호
flag = []
for i in range(n_of_vertex):
    flag.append(i)

total_weight = 0
# 순서대로 pop해서 kruskal 실행
for _ in range(n_of_edge):
    adj_list = edges.pop(0)
    if flag[adj_list[0]] != flag[adj_list[1]]:
        a = max(flag[adj_list[0]], flag[adj_list[1]])
        b = min(flag[adj_list[0]], flag[adj_list[1]])
        for i in range(n_of_vertex):
            if flag[i] == a:
                flag[i] = b
        total_weight += adj_list[2]

print(total_weight)
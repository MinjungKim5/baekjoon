## https://www.acmicpc.net/problem/11724
## 연결 요소의 개수

# 문제
# 방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

# 입력
# 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다.
# (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다.
#  (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

# 출력
# 첫째 줄에 연결 요소의 개수를 출력한다.

# 예제 입력 1 
# 6 5
# 1 2
# 2 5
# 5 1
# 3 4
# 4 6

# 예제 출력 1 
# 2
import sys

first_input = (sys.stdin.readline()).split(" ")
n_of_vertex = int(first_input[0])
m_of_edges = int(first_input[1])

flags = []
for i in range(n_of_vertex):
    flags.append(i)

def find_union(n):
    if flags[n] == n:
        return n
    my_union = find_union(flags[n])
    return my_union


for _ in range(m_of_edges):
    edge = (sys.stdin.readline()).split(" ")
    adj_info = [int(edge[0]) -1 , int(edge[1]) -1]
    a = find_union(adj_info[0])
    b = find_union(adj_info[1])
    # print(adj_info)
    if a != b:
        if a < b: flags[b] = a
        else: flags[a] = b

# print(flags)
flagset = set([])
for x in range(n_of_vertex):
    fff = find_union(x)
    flagset.add(fff)
# print(flagset)
print(len(flagset))
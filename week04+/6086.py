# https://www.acmicpc.net/problem/6086
# 최대 유량

import sys
n_of_pipes = int(input())

adjmatrix = [[0]*52 for _ in range(52)]
visited = [False] * 52

def ord_alpha(char):
    convert = ord(char)
    if convert < 91: return convert-65
    else: return convert-71

for _ in range(n_of_pipes): #인접행렬 작성
    instr = sys.stdin.readline().split(" ")
    a=ord_alpha(instr[0])
    b=ord_alpha(instr[1])
    c=int(instr[2])
    adjmatrix[a][b] += c
    adjmatrix[b][a] += c


def priority_BFS(a, flow):
    if adjmatrix[a][25] > 0:
        flow = min(flow, adjmatrix[a][25])
        adjmatrix[a][25] -= flow
        adjmatrix[25][a] -= flow
        return flow
    else:
        nodelist = []
        for idx in range(52): # 연결된 노드들 찾아서 리스트 인
            if visited[idx] == True: continue
            if adjmatrix[a][idx] > 0:
                nodelist.append([adjmatrix[a][idx], idx])
        nodelist.sort(reverse=True)
        for node in nodelist:
            visited[node[1]] = True
            minflow = min(flow, priority_BFS(node[1], min(flow, node[0])))
            if minflow == 0: continue
            adjmatrix[a][node[1]] -= minflow
            adjmatrix[node[1]][a] -= minflow
            return minflow
        return 0

sum = 0
while True:
    # 가중치 높은 재귀 다익스트라
    visited = [False] * 52
    visited[0] = True
    flow = priority_BFS(0,2000000000)
    sum += flow
    if flow == 0 or flow == 2000000000: print(sum); exit()
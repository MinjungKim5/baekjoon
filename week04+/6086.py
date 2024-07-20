# https://www.acmicpc.net/problem/6086
# 최대 유량

# 컨셉: A에서 시작해서 자기한테 연결된 링크 중 Z로 가는 링크와, 그게 아니면 서브노드 탐색 리턴값 을 합해준다.
import sys
nOfPipes = int(input())

adjlist = [[] for _ in range(100)]
visited = [False] * 100
visited[0] = True

def search(a):
    sum=0
    willVisit = adjlist[a]
    while(len(willVisit) != 0):
        row = willVisit.pop(0)
        if row[0] == 25: sum += row[1]
        elif visited[row[0]] == True: continue
        else:
            visited[row[0]] = True
            sum += min(search(row[0]), row[1])
    return sum

for _ in range(nOfPipes):
    instr = sys.stdin.readline().split(" ")
    a=ord(instr[0])-65
    b=ord(instr[1])-65
    c=int(instr[2])
    adjlist[a].append([b,c])
    adjlist[b].append([a,c])

print(search(0))

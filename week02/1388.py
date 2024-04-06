## https://www.acmicpc.net/problem/1388
## 바닥 장식

# 문제
# 형택이는 건축가이다. 지금 막 형택이는 형택이의 남자 친구 기훈이의 집을 막 완성시켰다.
# 형택이는 기훈이 방의 바닥 장식을 디자인했고, 이제 몇 개의 나무 판자가 필요한지 궁금해졌다.
# 나무 판자는 크기 1의 너비를 가졌고, 양수의 길이를 가지고 있다.
# 기훈이 방은 직사각형 모양이고, 방 안에는 벽과 평행한 모양의 정사각형으로 나누어져 있다.

# 이제 ‘-’와 ‘|’로 이루어진 바닥 장식 모양이 주어진다.
# 만약 두 개의 ‘-’가 인접해 있고, 같은 행에 있다면, 두 개는 같은 나무 판자이고,
# 두 개의 ‘|’가 인접해 있고, 같은 열에 있다면, 두 개는 같은 나무 판자이다.

# 기훈이의 방 바닥을 장식하는데 필요한 나무 판자의 개수를 출력하는 프로그램을 작성하시오.

# 입력
# 첫째 줄에 방 바닥의 세로 크기N과 가로 크기 M이 주어진다. 둘째 줄부터 N개의 줄에 M개의 문자가 주어진다.
# 이것은 바닥 장식 모양이고, '-‘와 ’|‘로만 이루어져 있다. N과 M은 50 이하인 자연수이다.

# 출력
# 첫째 줄에 문제의 정답을 출력한다.

# 예제 입력 1 
# 4 4
# ----
# ----
# ----
# ----

# 예제 출력 1 
# 4

first_input = input().split(" ")
vertical = int(first_input[0])
horizontal = int(first_input[1])

# 맵 그리기
map = []
for _ in range(vertical):
    map.append(list(input()))
    # print(map)

# Visited 만들기
visited = [[0 for _ in range(horizontal)] for _ in range(vertical)]

# 전체 맵을 순회하면서 다른 판자에 속하지 않은(visited가 아닌) 판자를 만나면 카운트하고 줄 잇기 시작
n_of_panja = 0
for j in range(vertical):
    for i in range(horizontal):
        if visited[j][i] == 0:
            visited[j][i] = 1
            n_of_panja += 1
            x, y = i, j
            # 줄 잇기: -인지 |인지 따라 분기
            # -면 가로로, |면 세로로 진행하며 다른 방향 만날때까지 같은 판자에 편입(visited)시키면서 줄 잇기
            if map[j][i] == "-":
                while x < horizontal - 1:
                    x += 1
                    if map[j][x] == "-": visited[j][x] = 1
                    else: break
            else:
                while y < vertical - 1:
                    y += 1
                    if map[y][i] == "|": visited[y][i] = 1
                    else: break

print(n_of_panja)
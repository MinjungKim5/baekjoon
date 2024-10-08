# https://www.acmicpc.net/problem/2239
# 스도쿠

# 문제
# 스도쿠는 매우 간단한 숫자 퍼즐이다.
# 9×9 크기의 보드가 있을 때, 각 행과 각 열, 그리고 9개의 3×3 크기의 보드에 1부터 9까지의 숫자가 중복 없이 나타나도록 보드를 채우면 된다.
# 하다 만 스도쿠 퍼즐이 주어졌을 때, 마저 끝내는 프로그램을 작성하시오.

# 입력
# 9개의 줄에 9개의 숫자로 보드가 입력된다. 아직 숫자가 채워지지 않은 칸에는 0이 주어진다.

# 출력
# 9개의 줄에 9개의 숫자로 답을 출력한다. 답이 여러 개 있다면 그 중 사전식으로 앞서는 것을 출력한다.
# 즉, 81자리의 수가 제일 작은 경우를 출력한다.

# 제한
# 12095번 문제에 있는 소스로 풀 수 있는 입력만 주어진다.
# C++17: 180ms
# Java 15: 528ms
# PyPy3: 2064ms
# 예제 입력 1 
# 103000509
# 002109400
# 000704000
# 300502006
# 060000050
# 700803004
# 000401000
# 009205800
# 804000107
# 예제 출력 1 
# 143628579
# 572139468
# 986754231
# 391542786
# 468917352
# 725863914
# 237481695
# 619275843
# 854396127

def sudoku(map, num):
    if num == 81:
        for i in range(9):
            for j in range(9):
                print(map[i][j],end="")
            print()
        exit()
    
    i = num//9
    j = num%9
    if map[i][j]:
        sudoku(map, num+1)
        return
    pool = [True] * 10
    pool[0] = False

    for x in range(9): # 가로체크
        pool[map[i][x]] = False
    for y in range(9): # 세로체크
        pool[map[y][j]] = False
    # 영역체크
    regionY = i//3
    regionX = j//3
    for x in range(3):
        for y in range(3):
            a = regionY*3+y
            b = regionX*3+x
            pool[map[a][b]] = False
    
    for n in range(1,10):
        if not pool[n]: continue
        map[i][j] = n
        sudoku(map, num+1)
        map[i][j] = 0

lines = []
for _ in range(9):
    ll = list(input().strip())
    line = list(map(int, ll))
    lines.append(line)

sudoku(lines, 0)
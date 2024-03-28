## https://www.acmicpc.net/problem/9663
## N-Queen

# 문제
# N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

# N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

# 입력
# 첫째 줄에 N이 주어진다. (1 ≤ N < 15)

# 출력
# 첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

# 예제 입력 1 
# 8

# 예제 출력 1 
# 92
"""
전략
0부터 시작하는 a번째퀸은 x좌표 a에 대해서
이미 체크인 된 자리로 인한 밴 방정식 y - seat[1]= a - seat[0]과
y - seat[1] = -a + seat[0]의 해 y를 제외한 위치에 순차적으로 체크인을 하고
점유 좌표 리스트 seats 에 등록한 뒤
a+1번째 퀸을 소환한다.
이후 퇴장할 때 점유좌표 리스트에서 체크아웃하고 리턴

n번째 퀸은 소환되는 즉시 카운트를 올리고 리턴
"""
def check_in(x, y):
    seats[x] = y
    print("  " * x + f"{x} queen checked in ({x}, {y}). now occupied seats are")
    print(seats)

def check_out(x):
    seats[x] = -1
    print("  " * x + f"{x} queen checked out. now occupied seats are")
    print(seats)  

def queen(a, n):
    global n_of_case
    global seats
    if a == n:
        # print("all queens have seated!")
        n_of_case += 1
        return
    # print(f"seeking vacant seat for {a} queen")
    # y값 이터레이션
    for b in range(n):
        check = True
        for i1 in range(a):
            if (b == seats[i1]) | ((b - seats[i1]) == (a - i1)) | ((b - seats[i1]) == (-a + i1)):
                check = False
                break
        if check == False:
            continue
        # 걸리는 조건이 없으면 체크인 후 다음 가로좌표(a+1)의 퀸 소환. 다음 퀸의 작업이 완료되면 체크아웃 
        check_in(a, b)
        # seats[a] = b
        queen(a+1, n)
        check_out(a)
        # seats[a] = -1
    return

n = int(input())
n_of_case = 0
seats = [-1 for _ in range(n)]
for zero_queen_y in range(n):
    check_in(0, zero_queen_y)
    # seats[0] = zero_queen_y
    queen(1,n)
    check_out(0)

print(n_of_case)
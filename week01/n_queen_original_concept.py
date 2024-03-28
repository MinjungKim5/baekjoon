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
"""전략
0부터 시작하는 a번째퀸은 x좌표 a의 모든 y값 b에 대해서 (a,b)가 밴 리스트에 없으면
해당 좌표로 생성되는 new_bans 작성 후
new_bans와 bans의 합집합 체크인을 하고
a+1번째 퀸을 소환한 뒤
자기가 밴했던 자리를 체크아웃하고 리턴.
n번째 퀸은 소환되는 즉시 카운트를 올리고 리턴
"""
   
# 지정 좌표가 밴하는 영역
def new_bans(cord):
    nb = set()
    for y in range(n):
        nb.add((cord[0], y))
    # x값 밴
    for x in range(n):
        nb.add((x, cord[1]))
    # y - b = x - a 밴
        candidate1 = (x, x-cord[0]+cord[1])
        if 0 <= candidate1[1] <= n-1:
            nb.add(candidate1)
    # y - b = -x + a 밴
        candidate2 = (x, -x+cord[0]+cord[1])
        if 0 <= candidate2[1] <= n-1:
            nb.add(candidate2)
    return nb    

def checkin(bans, newbans):
    return bans | newbans


def checkout(bans, diff):
    return bans - diff

def queen(a, n):
    global n_of_case
    global bans
    if a == n:
        # print("nth queen has born. call up n_of_case to celebrate!")
        n_of_case += 1
        return
    
    a_plus_one_reserved = 0
    for ban in bans:
        if ban[0] == a:
             a_plus_one_reserved += 1
            
    if a_plus_one_reserved == n:
        # print(f"no seat available for {a}queen")
        return
            
    
    for b in range(n):
        cord = (a, b)
        if cord not in bans:
            newbans = new_bans(cord)
            diff = newbans - bans
            bans = checkin(bans, newbans)
            # print("  " * a, end="")
            # print(f"{a} queen : checked in ", end="")
            # print(cord)
            # print("now banlist is")
            # print(bans)
            # print("  " * a, end="")
            # print(f"summoning {a+1} queen...")
            queen(a+1, n)
            bans = checkout(bans, diff)
            # print("  " * a, end="")
            # print(f"{a} queen checkout complete now banlist is")
            # print(bans)
    return

n = int(input())
bans = set()
n_of_case = 0
queen(0,n)
print(n_of_case)
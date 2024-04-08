## https://www.acmicpc.net/problem/9084
## 동전

# 문제
# 우리나라 화폐단위, 특히 동전에는 1원, 5원, 10원, 50원, 100원, 500원이 있다.
# 이 동전들로는 정수의 금액을 만들 수 있으며 그 방법도 여러 가지가 있을 수 있다.
# 예를 들어, 30원을 만들기 위해서는 1원짜리 30개 또는 10원짜리 2개와 5원짜리 2개 등의 방법이 가능하다.
# 동전의 종류가 주어질 때에 주어진 금액을 만드는 모든 방법을 세는 프로그램을 작성하시오.

# 입력
# 입력의 첫 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 10)가 주어진다.
# 각 테스트 케이스의 첫 번째 줄에는 동전의 가지 수 N(1 ≤ N ≤ 20)이 주어지고
# 두 번째 줄에는 N가지 동전의 각 금액이 오름차순으로 정렬되어 주어진다.
# 각 금액은 정수로서 1원부터 10000원까지 있을 수 있으며 공백으로 구분된다.
# 세 번째 줄에는 주어진 N가지 동전으로 만들어야 할 금액 M(1 ≤ M ≤ 10000)이 주어진다.
# 편의를 위해 방법의 수는 2^31 - 1 보다 작고, 같은 동전이 여러 번 주어지는 경우는 없다.

# 출력
# 각 테스트 케이스에 대해 입력으로 주어지는 N가지 동전으로 금액 M을 만드는 모든 방법의 수를 한 줄에 하나씩 출력한다.

# 예제 입력 1 
# 3
# 2
# 1 2
# 1000
# 3
# 1 5 10
# 100
# 2
# 5 7
# 22
# 예제 출력 1

# 501
# 121
# 1
import sys
sys.setrecursionlimit(100000)
testcase = int(input())

""" 재귀 코드
def case(money, i):
    # C0는 0
    if i == 0: coin = 0
    else: coin = coins[i-1]

    # 0원을 만드는 방법은 아무것도 넣지 않는 1가지.case(0,Ci) = 1
    if money == 0: return 1
    elif money <0: return 0

    # 0원으로 뭘 만드는 경우는 0원말고는 불가능. case(M,0) = 0
    if coin == 0: return 0

    # case(M,Ci) 에서 M<ci면 0, 
    return case(money, i-1) + case(money - coin, i)
"""

for _ in range(testcase):
    n_of_coins = int(input())
    coin_input = input().split(" ")
    coins = [int(coin_input[i]) for i in range(n_of_coins)]
    money = int(input())
    # print(coins)
    # print(case(money, n_of_coins))

    table = [[0 for _ in range(money + 1)] for _ in range(n_of_coins)]
    
    for i in range(n_of_coins):
        coin = coins[i]
        table[i][0] = 1
        if i == 0:
            for j in range(money+1):
                if j%coin == 0: table[i][j] = 1
            continue
        for j in range(1,money+1):
            if j >= coin: precase = table[i][j-coin]
            else: precase = 0
            table[i][j] = table[i-1][j] + precase
    print(table[n_of_coins-1][money])
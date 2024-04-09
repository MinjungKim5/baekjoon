## https://www.acmicpc.net/problem/11049
## 행렬 곱셈 순서

# 문제
# 크기가 N×M인 행렬 A와 M×K인 B를 곱할 때 필요한 곱셈 연산의 수는 총 N×M×K번이다.
# 행렬 N개를 곱하는데 필요한 곱셈 연산의 수는 행렬을 곱하는 순서에 따라 달라지게 된다.
# 예를 들어, A의 크기가 5×3이고, B의 크기가 3×2, C의 크기가 2×6인 경우에 행렬의 곱 ABC를 구하는 경우를 생각해보자.
# AB를 먼저 곱하고 C를 곱하는 경우 (AB)C에 필요한 곱셈 연산의 수는 5×3×2 + 5×2×6 = 30 + 60 = 90번이다.
# BC를 먼저 곱하고 A를 곱하는 경우 A(BC)에 필요한 곱셈 연산의 수는 3×2×6 + 5×3×6 = 36 + 90 = 126번이다.
# 같은 곱셈이지만, 곱셈을 하는 순서에 따라서 곱셈 연산의 수가 달라진다.
# 행렬 N개의 크기가 주어졌을 때, 모든 행렬을 곱하는데 필요한 곱셈 연산 횟수의 최솟값을 구하는 프로그램을 작성하시오.
# 입력으로 주어진 행렬의 순서를 바꾸면 안 된다.

# 입력
# 첫째 줄에 행렬의 개수 N(1 ≤ N ≤ 500)이 주어진다.
# 둘째 줄부터 N개 줄에는 행렬의 크기 r과 c가 주어진다. (1 ≤ r, c ≤ 500)
# 항상 순서대로 곱셈을 할 수 있는 크기만 입력으로 주어진다.

# 출력
# 첫째 줄에 입력으로 주어진 행렬을 곱하는데 필요한 곱셈 연산의 최솟값을 출력한다.
# 정답은 2^31-1 보다 작거나 같은 자연수이다. 또한, 최악의 순서로 연산해도 연산 횟수가 2^31-1보다 작거나 같다.

# 예제 입력 1 
# 3
# 5 3
# 3 2
# 2 6

# 예제 출력 1 
# 90

n_of_matrix = int(input())
# table에 각 행렬 데이터 저장
table = []
for i in range(n_of_matrix - 1):
    table.append([int(input().split(" ")[0]), i])
last_input = input().split(" ")
table.append([int(last_input[0]), n_of_matrix - 1])
table.append([int(last_input[1]), n_of_matrix])

# table을 오름차순으로 sort. pop(0)로 빼면서 볼 예정
que = sorted(table,reverse = True)
# print(que)

res = 0

while len(que) > 2: # 양 끝값만 남으면 
    tuple = que.pop(0)
    val = tuple[0]
    loc = tuple[1]
    # 양 끝이면 큐에 다시 넣어준다
    if loc == 0 or loc ==n_of_matrix:
        que.append(tuple)
        continue
    
    left_shift = 1
    right_shift = 1
    left_val = 1
    right_val = 1
    while True:
        if table[loc-left_shift][0]: 
            left_val = table[loc-left_shift][0]
            break
        left_shift += 1

    while True:
        if table[loc+right_shift][0]:
            right_val = table[loc+right_shift][0]
            break
        right_shift += 1
    
    res += val * left_val * right_val
    table[loc][0] = 0

print(res)



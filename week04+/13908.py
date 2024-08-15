# https://www.acmicpc.net/problem/13908
# 비밀번호

# 문제
# 웅찬이는 근성이 대단한 도둑이다. 그래서 금고를 털 때, 모든 조합을 눌러본다.
# 예를 들어 비밀번호가 3글자 라는 사실을 알 때, 000, 001, 002, 003, … 998, 999의 모든 조합을 눌러본다.
# 그러나 웅찬이는 선견지명이 있어서 비밀번호에 어떤 숫자가 들어가는지 일부 알 수 있다.
# 예를 들어 3글자 비밀번호에 0이 들어감을 안다면 999 와 같이 0이 들어가지 않는 수는 가능성이 없다. 그러나 000, 012, 030과 같은 수는 가능하다.
# 비밀번호의 길이와 선견지명으로 알게된 비밀번호의 일부 숫자가 주어질 때, 모든 가능한 비밀번호의 개수를 출력하는 프로그램을 작성하시오.

# 입력
# 첫줄에 비밀번호의 길이 n (1 ≤ n ≤ 7), 선견지명으로 알게된 비밀번호에 들어가는 수 m(0 ≤ m ≤ n) 이 주어지고,
# 둘째 줄에 m개의 서로 다른 숫자(0~9)가 주어진다. m이 0인 경우 둘째 줄은 주어지지 않는다.

# 출력
# 가능한 모든 비밀번호의 개수를 출력한다.

# 예제 입력 1 
# 2 1
# 7
# 예제 출력 1 
# 19

n, m = map(int, input().strip().split(" "))
if m == 0: print(10**n); exit()
arr = [100 for _ in range(n)]
count = 0
def fill(seat, num):
    global arr, count
    check = [False for _ in range(m)]

    arr[seat] = num
    for i in range(seat+1):
        if arr[i] < m: check[arr[i]] = True
    complete = True
    for c in check: complete = complete and c
    if complete: count += 10**(n-seat-1); return
    
    if seat < n-1:
        for i in range(10):
            fill(seat+1, i)

for i in range(10): fill(0,i)
print(count)
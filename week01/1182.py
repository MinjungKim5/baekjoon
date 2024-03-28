## https://www.acmicpc.net/problem/1182
## 부분수열의 합

# 문제
# N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

# 입력
# 첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.

# 출력
# 첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.

# 예제 입력 1 
# 5 0
# -7 -3 -2 5 8
# 예제 출력 1 
# 1

intext1 = input().split(" ")
n = int(intext1[0])
s = int(intext1[1])
intext2 = input().split(" ")
nums = []
for indx in range(n):
    nums.append(int(intext2[indx]))
count = 0
dl = []
for _ in range(n):
    dl.append(0)

def digital_list(num):
    for i in range(n):
        dl[-1-i] = num % 2
        num = num // 2
    return dl

for i in range(2 ** n - 1):
    bool_list = digital_list(i+1)
    sum = 0
    for j in range(n):
        sum += nums[j] * bool_list[j]
    if sum == s:
        count += 1

print(count)
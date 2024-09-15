# https://www.acmicpc.net/problem/13144
# List of Unique Numbers

# 문제
# 길이가 N인 수열이 주어질 때, 수열에서 연속한 1개 이상의 수를 뽑았을 때 같은 수가 여러 번 등장하지 않는 경우의 수를 구하는 프로그램을 작성하여라.

# 입력
# 첫 번째 줄에는 수열의 길이 N이 주어진다. (1 ≤ N ≤ 100,000)
# 두 번째 줄에는 수열을 나타내는 N개의 정수가 주어진다. 수열에 나타나는 수는 모두 1 이상 100,000 이하이다.

# 출력
# 조건을 만족하는 경우의 수를 출력한다.

# 예제 입력 1 
# 5
# 1 2 3 4 5
# 예제 출력 1 
# 15
# 예제 입력 2 
# 5
# 1 2 3 1 2
# 예제 출력 2 
# 12
# 예제 입력 3 
# 5
# 1 1 1 1 1
# 예제 출력 3 
# 5

nOfNumbers = int(input())
nums = list(map(int, input().split()))
check = [-1] * 100001
lowlimit = -1
sum = 0
for n in range(nOfNumbers):
    number = nums[n]
    sum += min(n-check[number],n-lowlimit)
    lowlimit = max(lowlimit,check[number])
    check[number] = n
print(sum)
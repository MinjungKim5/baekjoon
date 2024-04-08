## https://www.acmicpc.net/problem/11053
## 가장 긴 증가하는 부분 수열

# 문제
# 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
# 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에
# 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

# 입력
# 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
# 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

# 출력
# 첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
# 예제 입력 1 
# 6
# 10 20 10 30 20 50
# 예제 출력 1 
# 4

# 이전 까지 최고 부분수열보다 큰 값이면 업데이트해주는 식으로 짰으나 크다 작다 하는 경우 틀림.
# 각 값의 시작점에서부터 위 방식으로 구한다음에 그 중에 맥스값을 찾는 방식이어야 할것 같은데

length = int(input())
num_list = input().split(" ")
nums = [int(num_list[i]) for i in range(length)]

# print(nums)

def lis(start,end):
    # if 1: return [nums[0], 1]
    pre = lis(len-1)
    if pre[0] < nums[len-1]: return [nums[len-1], pre[1]+1]
    elif pre[1] == 1 and pre[0] >= nums[len-1]: return[nums[len-1], 1]
    else: return pre

print(lis(length)[1])
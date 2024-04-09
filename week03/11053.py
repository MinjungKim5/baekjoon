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

# 이전 최대값보다 크면 그냥 붙이고 아니면 이분탐색 위치의 수와 교환


import bisect

length = int(input())
num_list = input().split(" ")
nums = [int(num_list[i]) for i in range(length)]
# nums.insert(0, 0)
# dp_table = [0 for _ in range(length + 1)]
sequence = [nums[0]]
for i in range(1,length):
    if nums[i] > sequence[-1]: sequence.append(nums[i])
    else:
        location = bisect.bisect_left(sequence,nums[i])
        sequence[location] = nums[i]

print(len(sequence))

# for i in range(1, length+1):
#     for j in range(i-1,0,-1):
#         if nums[i] > nums[j]: 
#             x_low = j
#             break
#     for k in range(i-1,0,-1):
#         if nums[i] <= nums[k]:
#             x_high = k
#             break
#     dp_table[i] = max(dp_table[x_low]+1, dp_table[x_high])

# print(dp_table)
# print(dp_table[length])
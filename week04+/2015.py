import sys
input = sys.stdin.readline

nOfNums, k = map(int,input().split())
sums = {0:1}
count = 0
sum = 0
nums = list(map(int,input().strip().split()))
for num in nums:
    sum += num
    count += sums.get(sum-k,0)
    sums[sum] = sums.get(sum,0)+1
print(count)
# https://www.acmicpc.net/problem/1744
# 수 묶기

# 문제
# 길이가 N인 수열이 주어졌을 때, 그 수열의 합을 구하려고 한다. 하지만, 그냥 그 수열의 합을 모두 더해서 구하는 것이 아니라, 수열의 두 수를 묶으려고 한다.
# 어떤 수를 묶으려고 할 때, 위치에 상관없이 묶을 수 있다. 하지만, 같은 위치에 있는 수(자기 자신)를 묶는 것은 불가능하다.
# 그리고 어떤 수를 묶게 되면, 수열의 합을 구할 때 묶은 수는 서로 곱한 후에 더한다.
# 예를 들면, 어떤 수열이 {0, 1, 2, 4, 3, 5}일 때, 그냥 이 수열의 합을 구하면 0+1+2+4+3+5 = 15이다.
# 하지만, 2와 3을 묶고, 4와 5를 묶게 되면, 0+1+(2*3)+(4*5) = 27이 되어 최대가 된다.
# 수열의 모든 수는 단 한번만 묶거나, 아니면 묶지 않아야한다.
# 수열이 주어졌을 때, 수열의 각 수를 적절히 묶었을 때, 그 합이 최대가 되게 하는 프로그램을 작성하시오.

# 입력
# 첫째 줄에 수열의 크기 N이 주어진다. N은 50보다 작은 자연수이다. 둘째 줄부터 N개의 줄에 수열의 각 수가 주어진다.
# 수열의 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

# 출력
# 수를 합이 최대가 나오게 묶었을 때 합을 출력한다. 정답은 항상 231보다 작다.

# 예제 입력 1 
# 4
# -1
# 2
# 1
# 3
# 예제 출력 1 
# 6
# 예제 입력 2 
# 6
# 0
# 1
# 2
# 4
# 3
# 5
# 예제 출력 2 
# 27
# 예제 입력 3 
# 1
# -1
# 예제 출력 3 
# -1
# 예제 입력 4 
# 3
# -1
# 0
# 1
# 예제 출력 4 
# 1

nOfNums = int(input())
nums = []
minuscount = 0
zerocount = 0
over1count = 0
sum = 0
for _ in range(nOfNums):
    num = int(input())
    if num == 0: zerocount+=1
    elif num < 0: minuscount+=1
    elif num > 1: over1count+=1
    else: sum+=1
    nums.append(num)

nums.sort()
if minuscount%2:
    for i in range(0,minuscount-1,2):
        sum += nums[i]*nums[i+1]
    if zerocount == 0: sum += nums[minuscount-1]
else:
    for i in range(0,minuscount,2):
        sum += nums[i]*nums[i+1]

if over1count%2:
    for i in range(nOfNums-1, nOfNums-over1count, -2):
        sum += nums[i]*nums[i-1]
    sum+=nums[nOfNums-over1count]
else:
    for i in range(nOfNums-1, nOfNums-over1count-1, -2):
        sum += nums[i]*nums[i-1]
print(sum)
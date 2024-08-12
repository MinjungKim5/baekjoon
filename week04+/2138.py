# 전구와 스위치

# 문제
# N개의 스위치와 N개의 전구가 있다. 각각의 전구는 켜져 있는 상태와 꺼져 있는 상태 중 하나의 상태를 가진다.
# i(1 < i < N)번 스위치를 누르면 i-1, i, i+1의 세 개의 전구의 상태가 바뀐다.
# 즉, 꺼져 있는 전구는 켜지고, 켜져 있는 전구는 꺼지게 된다. 1번 스위치를 눌렀을 경우에는 1, 2번 전구의 상태가 바뀌고, N번 스위치를 눌렀을 경우에는 N-1, N번 전구의 상태가 바뀐다.
# N개의 전구들의 현재 상태와 우리가 만들고자 하는 상태가 주어졌을 때, 그 상태를 만들기 위해 스위치를 최소 몇 번 누르면 되는지 알아내는 프로그램을 작성하시오.

# 입력
# 첫째 줄에 자연수 N(2 ≤ N ≤ 100,000)이 주어진다.
# 다음 줄에는 전구들의 현재 상태를 나타내는 숫자 N개가 공백 없이 주어진다.
# 그 다음 줄에는 우리가 만들고자 하는 전구들의 상태를 나타내는 숫자 N개가 공백 없이 주어진다.
# 0은 켜져 있는 상태, 1은 꺼져 있는 상태를 의미한다.

# 출력
# 첫째 줄에 답을 출력한다. 불가능한 경우에는 -1을 출력한다.

# 예제 입력 1 
# 3
# 000
# 010
# 예제 출력 1 
# 3

n_of_bulb = int(input())

def reverse(arr, goal, count, changed):
    for i in range(n_of_bulb-1, -1, -1):
        if arr[i] == goal[i]: continue
        if i == 0: return -1
        if i == n_of_bulb-1 and changed==False:
            arr[i] = 1-arr[i]
            arr[i-1] = 1-arr[i-1]
            count +=1
        else:
            arr[i] = 1-arr[i]
            arr[i-1] = 1-arr[i-1]
            if i > 1: arr[i-2] = 1-arr[i-2]
            count +=1
    return count

def check(arr, goal):
    count = 0
    changed = False
    for i in range(n_of_bulb):
        if arr[i] == goal[i]: continue
        if i == 0 and arr[i+1] == goal[i+1]:
            arr[i] = 1-arr[i]
            arr[i+1] = 1-arr[i+1]
            count += 1
        elif i == n_of_bulb-1: count = reverse(arr, goal, count, changed)
        else:
            arr[i] = 1-arr[i]
            arr[i+1] = 1-arr[i+1]
            if i+2 < n_of_bulb: arr[i+2] = 1-arr[i+2]
            if i == n_of_bulb-2: changed=True
            count += 1
    if arr[0] != goal[0]: return -1
    return count


in1 = input().strip()
in1r = in1[::-1]
in2 = input().strip()
in2r = in2[::-1]
if in1==in2: print(0); exit()
if n_of_bulb == 1: print(1); exit()
arr = list(map(int,list(in1)))
rarr = list(map(int,list(in1r)))
goal = list(map(int,list(in2)))
rgoal = list(map(int,list(in2r)))
if n_of_bulb == 2:
    if (arr[0]+arr[1]+goal[0]+goal[1])%2 == 1: print(-1)
    else: print(1)
    exit()

res1 = check(arr, goal)
res2 = check(rarr, rgoal)
if res1 == -1 and res2 == -1: print(-1)
elif res1 == -1: print(res2)
elif res2 == -1: print(res1)
else: print(min(res1, res2))
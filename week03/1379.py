# https://www.acmicpc.net/problem/1379
# 강의실 2

# 문제
# N개의 강의가 있다. 우리는 모든 강의의 시작하는 시간과 끝나는 시간을 알고 있다.
# 이때, 우리는 최대한 적은 수의 강의실을 사용하여 모든 강의가 이루어지게 하고 싶다.
# 물론, 한 강의실에서는 동시에 2개 이상의 강의를 진행할 수 없고, 한 강의의 종료시간과 다른 강의의 시작시간이 겹치는 것은 상관없다.
# 필요한 최소 강의실 수 K와, 각 강의마다 강의실을 배정하는 프로그램을 작성하시오.

# 입력
# 첫째 줄에 강의의 개수 N(1 ≤ N ≤ 100,000)이 주어진다.
# 둘째 줄부터 N개의 줄에 걸쳐 각 줄마다 세 개의 정수가 주어지는데, 순서대로 강의 번호, 강의 시작 시간, 강의 종료 시간을 의미한다.
# 강의 번호는 1부터 N까지 붙어 있으며, 입력에서 꼭 순서대로 주어지지 않을 수 있으나 한 번씩만 주어진다.
# 강의 시작 시간과 강의 종료 시간은 0 이상 10억 이하의 정수이고, 시작 시간은 종료 시간보다 작다.

# 출력
# 첫째 줄에 필요한 최소 강의실 개수 K를 출력한다. 둘째 줄부터 N개의 줄에 걸쳐 각 강의에 배정할 강의실 번호를 순서대로 출력한다.
# 편의상 강의실 번호는 1, 2, ..., K 로 매긴다.

# 예제 입력 1 
# 8
# 6 15 21
# 7 20 25
# 1 3 8
# 3 2 14
# 8 6 27
# 2 7 13
# 4 12 18
# 5 6 20

# 예제 출력 1 
# 5
# 4
# 3
# 2
# 4
# 1
# 3
# 4
# 5

import sys
import heapq
n_of_lecture = int(input())
lectures = []

## 강의를 [시작, 종료, 번호]로 lectures에 저장
for i in range(n_of_lecture):
    raw_input = sys.stdin.readline().split(" ")
    lecture = [int(raw_input[1]), int(raw_input[2]), int(raw_input[0])]
    lectures.append(lecture)

## 강의를 시작시간순으로 정렬
lectures = sorted(lectures)
# print(lectures)

# lec_rm은 {index}번 강의가 진행될 강의실
lec_rm = [0]*(n_of_lecture + 1)

## 가장 먼저 시작하는 강의 하나는 넣고 시작
l1 = lectures.pop(0)
lec_rm[l1[2]] = 1
# 강의실 정보 rooms는 각 강의실의 현재까지 마지막 강의의 (종료시간, 강의번호) 튜플이 저장됨
rooms = [(l1[1], l1[2])]
heapq.heapify(rooms)

for lecture in lectures:
    # 강의들 중에 끝나는 시간이 가장 이른 것 뒤에 올수있는지 확인
    earliet = rooms[0]
    
    if lecture[0] >= earliet[0]: # 들어갈 수 있으면, 팝해서 본 강의실 번호를 받고 강의실 정보에 추가
        lec_rm[lecture[2]] = lec_rm[earliet[1]]
        heapq.heappop(rooms)

    else: # 안되면, 현재 있는 강의실 수 +1 한 강의실 번호를 받고 강의실 정보에 추가
        lec_rm[lecture[2]] = len(rooms) + 1

    heapq.heappush(rooms,(lecture[1], lecture[2]))
    # print(rooms)
    # print(lec_rm)

print(len(rooms))
for i in range(1,n_of_lecture+1):
    print(lec_rm[i])
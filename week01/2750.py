## https://www.acmicpc.net/problem/2750
## 수 정렬하기

# 문제
# N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

# 입력
# 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다.
# 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

# 출력
# 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

# 예제 입력 1 
# 5
# 5
# 2
# 3
# 4
# 1

# 예제 출력 1
# 1
# 2
# 3
# 4
# 5

def mySort(numlist):
    oldlist = numlist.copy()
    for i in range(len - 1):
        # print(f"i = {i}")
        if numlist[i] > numlist[i + 1]:
            bigger = numlist[i]
            numlist[i] = numlist[i + 1]
            numlist [i + 1] = bigger
    #         print("change!: ", end="")
    #         print(numlist)
        # else:
    #         print("no change: ", end="")
    #         print(numlist)
    # print("oldlist is ", end="")
    # print(oldlist)
    # print("now numlist is ", end="")
    # print(numlist)
    if oldlist == numlist: return
        # print("----------끝----------")
        # print(numlist)
        # return
    # print("----------다시----------")
    numlist = mySort(numlist)



len = int(input())
numlist = []
for i in range(len):
    numlist.append(int(input()))

mySort(numlist)
for num in numlist:
    print(num)
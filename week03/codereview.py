import sys
input = sys.stdin.readline

N = int(input())  # 계단 개수
stair = [[]]  # 계단 리스트
for _ in range(N):
    stair.append(int(input()))

dp = [[0] * (N + 1) for _ in range(N + 1)]  # dp테이블 초기화 
print(dp)
for y in range(1, N + 1):
    for x in range(1, N + 1):
        if y >= 3:  # 세번째 계단 이상일 때
                if dp[x][y-1] != dp[x][y-2] and dp[x][y-2] != dp[x][y-3]:  # 두번 연속 밟았다면
                    dp[x][y] = dp[x][y-1]  # 이번 계단을 밟지 않는다

                elif dp[x][y-1] == 0 or dp[x][y-1] == dp[x][y-2]:  # 전칸 안밟았으면 이번에 무조건 밟기
                    dp[x][y] = dp[x][y-1] + stair[y]

                else:
                    if y < N and stair[y] >= stair[y+1]:  # 이번 계단의 크기가 더 크면 밟음
                        dp[x][y] = dp[x][y-1] + stair[y]
                        if x >= 3:  # 이전에 구한 값과 같다면 다른 선택을 하게 하기
                            if dp[x-2][y] == dp[x][y]:
                                dp[x][y] = dp[x][y-1]
                    else:  # 다음 계단의 크기가 더 크다면 넘어가기
                        dp[x][y] = dp[x][y-1]
                        if x >= 3:  # 이전에 구한 값과 같다면 다른 선택을 하게 하기
                            if dp[x-2][y] == dp[x][y]:
                                dp[x][y] = dp[x][y-1] + stair[y]

        elif y == 2:  # 두번째 계단일 때 첫칸 안밟았으면 밟기
            if dp[x][y-1] == 0:
                dp[x][y] = stair[y]
            else:
                if y < N and stair[y] >= stair[y+1]:  # 이번 계단의 크기가 더 크면 밟음
                    dp[x][y] = dp[x][y-1] + stair[y]
                else:  # 다음 계단의 크기가 더 크다면 넘어가기
                    dp[x][y] = dp[x][y-1]


        else:  # 첫 칸은 번갈아가면서 밟는다
            if dp[x-1][y] == 0:
                dp[x][y] += stair[y]

        print(dp)


result = []
for i in dp:
    result.append(i[-1])

# for i in dp:
#     print(i)
print(max(result))
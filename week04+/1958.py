# https://www.acmicpc.net/problem/1958
# LCS 3

# 문제
# 문자열과 놀기를 세상에서 제일 좋아하는 영식이는 오늘도 문자열 2개의 LCS(Longest Common Subsequence)를 구하고 있었다.
# 어느 날 영식이는 조교들이 문자열 3개의 LCS를 구하는 것을 보았다. 영식이도 도전해 보았지만 실패하고 말았다.
# 이제 우리가 할 일은 다음과 같다. 영식이를 도와서 문자열 3개의 LCS를 구하는 프로그램을 작성하라.

# 입력
# 첫 줄에는 첫 번째 문자열이, 둘째 줄에는 두 번째 문자열이, 셋째 줄에는 세 번째 문자열이 주어진다.
# 각 문자열은 알파벳 소문자로 이루어져 있고, 길이는 100보다 작거나 같다.

# 출력
# 첫 줄에 첫 번째 문자열과 두 번째 문자열과 세 번째 문자열의 LCS의 길이를 출력한다.

# 예제 입력 1 
# abcdefghijklmn
# bdefg
# efg
# 예제 출력 1 
# 3

first = input().strip()
second = input().strip()
third = input().strip()

dptable = [[[0 for _ in range(len(third)+1)] for _ in range(len(second)+1)] for _ in range(len(first)+1)]
for i in range(1,len(first)+1):
    for j in range(1, len(second)+1):
        for k in range(1, len(third)+1):
            if first[i-1] == second[j-1] and second[j-1] == third[k-1]: dptable[i][j][k] = dptable[i-1][j-1][k-1] +1
            else: dptable[i][j][k] = max(dptable[i-1][j][k], dptable[i][j-1][k], dptable[i][j][k-1])

print(dptable[-1][-1][-1])
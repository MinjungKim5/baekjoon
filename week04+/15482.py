# https://www.acmicpc.net/problem/15482
# 한글 LCS

# 문제
# LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때,
# 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
# 예를 들어, "최백준"과 "백준온라인"의 LCS는 "백준"이고, "스타트링크"와 "스트라토캐스터"의 LCS는 "스트"이다.

# 입력
# 첫째 줄과 둘째 줄에 두 문자열이 주어진다.
# 문자열은 최대 1000글자이고, 유니코드 U+AC00(가)부터 U+D7A3(힣)까지로만 이루어져 있으며, UTF-8로 인코딩 되어 있다.

# 출력
# 첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

# 예제 입력 1 
# 최백준
# 백준온라인
# 예제 출력 1 
# 2
# 예제 입력 2 
# 스타트링크
# 스트라토캐스터
# 예제 출력 2 
# 2
# 예제 입력 3 
# 선데이코딩
# 딩코이데선
# 예제 출력 3 
# 1
# 예제 입력 4 
# 가나다라가나다라
# 가다나가다라
# 예제 출력 4 
# 5

a = input().strip()
b = input().strip()
dptable = [[0]*(len(b)+1) for _ in range(len(a)+1)]
for i in range(1, len(a)+1):
    for j in range(1, len(b)+1):
        if (a[i-1] == b[j-1]): dptable[i][j] = dptable[i-1][j-1] + 1
        else: dptable[i][j] = max(dptable[i-1][j], dptable[i][j-1])
print(dptable[-1][-1])
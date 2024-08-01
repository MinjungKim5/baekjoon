# https://www.acmicpc.net/problem/2749
# 피보나치 수 3

# 입력
# 첫째 줄에 n이 주어진다. n은 1,000,000,000,000,000,000보다 작거나 같은 자연수이다.

# 출력
# 첫째 줄에 n번째 피보나치 수를 1,000,000으로 나눈 나머지를 출력한다.

a,b,temp = 1, 1, 1
# n = int(input())
n = int(input())%1500000
if n == 0: print(0); exit()
if n < 3: print(1); exit()
for i in range(n-2):
    temp = b
    b = (a + b)%1000000
    a = temp
print(b)
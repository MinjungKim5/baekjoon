# https://www.acmicpc.net/problem/1456
# 거의 소수

# 문제
# 어떤 수가 소수의 N제곱(N ≥ 2) 꼴일 때, 그 수를 거의 소수라고 한다.
# 두 정수 A와 B가 주어지면, A보다 크거나 같고, B보다 작거나 같은 거의 소수가 몇 개인지 출력한다.

# 입력
# 첫째 줄에 왼쪽 범위 A와 오른쪽 범위 B가 공백 한 칸을 사이에 두고 주어진다.

# 출력
# 첫째 줄에 총 몇 개가 있는지 출력한다.

# 제한
# 1 ≤ A ≤ B ≤ 1014
# 예제 입력 1 
# 1 1000
# 예제 출력 1 
# 25
# 예제 입력 2 
# 1 10
# 예제 출력 2 
# 3
# 예제 입력 3 
# 5324 894739
# 예제 출력 3 
# 183

import math

a,b = map(int,input().split())
primes = [2]
for num in range(3,math.floor(math.sqrt(b))+1):
    sosu = True
    for prime in primes:
        if prime*prime > num: break
        if num%prime == 0: sosu = False; break
    if sosu: primes.append(num)

count = 0
for prime in primes:
    n = prime*prime
    while b >= n:
        if a <= n and n <= b: count +=1
        n *= prime
print(count)
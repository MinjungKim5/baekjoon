## https://www.acmicpc.net/problem/9020
## 골드바흐 추측

# 문제
# 1보다 큰 자연수 중에서  1과 자기 자신을 제외한 약수가 없는 자연수를 소수라고 한다.
# 예를 들어, 5는 1과 5를 제외한 약수가 없기 때문에 소수이다.
# 하지만, 6은 6 = 2 × 3 이기 때문에 소수가 아니다.

# 골드바흐의 추측은 유명한 정수론의 미해결 문제로, 2보다 큰 모든 짝수는 두 소수의 합으로 나타낼 수 있다는 것이다.
# 이러한 수를 골드바흐 수라고 한다. 또, 짝수를 두 소수의 합으로 나타내는 표현을 그 수의 골드바흐 파티션이라고 한다.
# 예를 들면, 4 = 2 + 2, 6 = 3 + 3, 8 = 3 + 5, 10 = 5 + 5, 12 = 5 + 7, 14 = 3 + 11, 14 = 7 + 7이다.
# 10000보다 작거나 같은 모든 짝수 n에 대한 골드바흐 파티션은 존재한다.

# 2보다 큰 짝수 n이 주어졌을 때, n의 골드바흐 파티션을 출력하는 프로그램을 작성하시오.
# 만약 가능한 n의 골드바흐 파티션이 여러 가지인 경우에는 두 소수의 차이가 가장 작은 것을 출력한다.

# 입력
# 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고 짝수 n이 주어진다.

# 출력
# 각 테스트 케이스에 대해서 주어진 n의 골드바흐 파티션을 출력한다.
# 출력하는 소수는 작은 것부터 먼저 출력하며, 공백으로 구분한다.

# 제한
# 4 ≤ n ≤ 10,000

# 예제 입력 1 
# 3
# 8
# 10
# 16

# 예제 출력 1 
# 3 5
# 5 5
# 5 11

"""
소수판별(num): //소수이면 true, 아니면 false를 뱉는다.
	num이 2이면 True 반환
	num이 짝수이면 False 반환
	num이 프라임풀에 있으면: True 반환
	프라임풀 이터레이션:
		만약 num이 프라임풀의 현재소수 제곱보다 작으면 브레이크
		만약 num이 프라임풀의 현재소수로 나눠지면 False 반환	
	다 돌면 True 반환
근처소수(n/2): //n/2보다 크거나 같은 근처 소수를 찾는다
	이터레이션 n/2+i:
		소수판별(n/2+i)이 참이면 n/2+i값 리턴
		아니면 컨티뉴
		
소수판별(원래 수 - 근처소수)이 소수이면 (원래수-근처소수) 근처소수를 출력
아니면 근처소수를 키워서 계속 이터레이션
"""

prime_pool = [3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127]

#소수 판별
def check_prime(candidate):
    if candidate == 2: return True
    if candidate % 2 == 0: return False
    if candidate in prime_pool: return True
    
    for prime in prime_pool:
        if prime**2 > candidate: break
        if candidate % prime == 0: return False
    return True

#근처 소수 찾기
def nearest_prime(num):
    i = 0
    while True:
        # print(f"check whether {num + i} is prime")
        if check_prime(num + i) == True: return (num + i)
        else: i += 1

len = int(input())
nums = []
for _ in range(len):
    nums.append(int(input()))
for num in nums:
    half = int(num/2)
    big = nearest_prime(half)
    while True:
        small = num - big
        if check_prime(small):
            print(f"{small} {big} ")
            break
        big = nearest_prime(big + 1)
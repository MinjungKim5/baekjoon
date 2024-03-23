## https://www.acmicpc.net/problem/1978

# 소수 찾기

# 문제
# 주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

# 입력
# 첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

# 출력
# 주어진 수들 중 소수의 개수를 출력한다.

# 예제 입력 1 
# 4
# 1 3 5 7

# 예제 출력 1 
# 3
import sys
primePool = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41]

def checkPrime(ipryuk):
    nums = ipryuk.split(" ")
    primes = 0
    for num in nums:
        num = int(num)
        if num in primePool:
            primes += 1
        elif num < 40:
            continue
        else:
            i = 0
            check = True
            while primePool[i]*primePool[i] < num:
                if num % primePool[i] == 0:
                    check = False
                    break
                i += 1

            if check == True:
                primes += 1
    return primes

input()
result = checkPrime(input())
print(result)
// https://www.acmicpc.net/problem/9527
// 1의 개수 세기

// 문제
// 두 자연수 A, B가 주어졌을 때, A ≤ x ≤ B를 만족하는 모든 x에 대해 x를 이진수로 표현했을 때 1의 개수의 합을 구하는 프로그램을 작성하시오.

// 입력
// 첫 줄에 두 자연수 A, B가 주어진다. (1 ≤ A ≤ B ≤ 10^16)

// 출력
// 1의 개수를 세어 출력한다.

// 예제 입력 1 
// 2 12
// 예제 출력 1 
// 21

#include <stdio.h>

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    b += 1;
    long long sum1 = 0, sum2 = 0;
    long long pow1 = 1;
    while (pow1 < 55) {
        sum1 += (b/((long long)1 << pow1))*((long long)1<<(pow1-1));
        if (b%((long long)1 << pow1) > ((long long)1<<(pow1-1))) {
            sum1 += b%((long long)1 << pow1) - ((long long)1<<(pow1-1));
        }
        pow1++;
    }
    long long pow2 = 1;
    while (pow2 < 55) {
        sum2 += (a/((long long)1 << pow2))*((long long)1<<(pow2-1));
        if (a%((long long)1 << pow2) > ((long long)1<<(pow2-1))) {
            sum2 += a%((long long)1 << pow2) - ((long long)1<<(pow2-1));
        }
        pow2++;
    }
    printf("%lld", sum1-sum2);
}
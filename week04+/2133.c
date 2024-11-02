// https://www.acmicpc.net/problem/2133
// 타일 채우기

// 문제
// 3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

// 입력
// 첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

// 출력
// 첫째 줄에 경우의 수를 출력한다.

// 예제 입력 1 
// 2
// 예제 출력 1 
// 3

#include <stdio.h>

int main() {
    int dp[16] = {0, };
    dp[0] = 1;
    dp[1] = 3;
    for (int i = 2; i < 16; i++) {
        dp[i] = dp[i-1]*3;
        for (int j = 0; j < i-1; j++) dp[i] += dp[j]*2;
    }
    int n;
    scanf("%d",&n);
    if (n%2) printf("0");
    else printf("%d",dp[n/2]);
    return 0;
}
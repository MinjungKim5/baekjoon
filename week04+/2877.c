// https://www.acmicpc.net/problem/2877
// 4와 7

// 문제
// 창영이는 4와 7로 이루어진 수를 좋아한다. 창영이가 좋아하는 수 중에 K번째 작은 수를 구해 출력하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 K(1 ≤ K ≤ 10^9)가 주어진다.

// 출력
// 첫째 줄에 창영이가 좋아하는 숫자 중 K번째 작은 수를 출력한다.

// 예제 입력 1 
// 1
// 예제 출력 1 
// 4
// 예제 입력 2 
// 2
// 예제 출력 2 
// 7
// 예제 입력 3 
// 3
// 예제 출력 3 
// 44

#include <stdio.h>
#include <string.h>

int main() {
    int k;
    scanf("%d",&k);
    int standard[32];
    for (int i = 0; i < 32; i++) {
        standard[i] = (1 << (i+1)) - 2;
    }
    char str[32] = "";
    while (k > 2) {
        int i = 1;
        while (1) {
            if (standard[i] < k && k <= standard[i+1]) break;
            else i++;
        }
        if (standard[i] + (1 << i) < k) {
            str[strlen(str)] = '7';
            k -= (1 << (i+1));
        }
        else {
            str[strlen(str)] = '4';
            k -= (1 << i);
        }
        str[strlen(str)] = '\0';
    }
    if (k == 2) {
        str[strlen(str)] = '7';
    }
    else {
        str[strlen(str)] = '4';
    }
    str[strlen(str)] = '\0';
    printf("%s",str);
}
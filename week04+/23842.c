// https://www.acmicpc.net/problem/23842
// 성냥개비

// 문제
// 동빈이는 내일 TV 프로그램 "문제적 유니" 에 출연한다. 평소 애청자였던 동빈이는 성냥개비 문제가 자주 출제된다는 사실을 알았고, 오늘 예습하기로 했다.
// 성냥개비는 다음과 같이 숫자를 디지털 형식으로 표현하는데, 각 숫자에 필요한 성냥개비 수는 그림과 같다.
// 동빈이가 연습할 문제는 "올바른 수식 만들기" 문제이고, 다음의 조건들을 만족해야 한다.
// 수식은 □□+□□=□□ 의 형태이고, 각 빈칸에는 0~9의 숫자가 들어간다.
// 모든 수는 항상 두 자릿수에 맞게 표현해야 한다.
// 예시로, 27인 경우에는 "27", 5인 경우에는 "05"로 표현한다
// "+" 와 "=" 에도 각각 두 개의 성냥개비가 필요하다. 
// N개의 성냥개비가 주어졌을 때, 성냥을 모두 사용하여 조건을 만족하는 수식을 만들 수 있을까? 가능한 답이 없다면 impossible을 출력한다.

// 입력
// 성냥개비의 개수 N이 주어진다. (1 ≤ N ≤ 50)

// 출력
// 첫 줄에 □□+□□=□□ 형태로 답을 출력한다.
// 만약 가능한 답이 없다면 impossible 을 출력한다.
// 가능한 답이 여러 개인 경우 그 중 하나를 출력한다.

// 예제 입력 1 
// 24
// 예제 출력 1 
// 00+11=11
// 숫자가 0으로 시작할 수 있음을 주의하자.
// 예제 입력 2 
// 10
// 예제 출력 2 
// impossible

#include <stdio.h>
int main() {
    char *arr[51] = {"impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible", "11+11=22", "01+11=12", "00+11=11", "01+13=14", "00+17=17", "01+15=16", "00+14=14", "01+18=19", "00+12=12", "01+01=02", "00+01=01", "01+03=04", "00+07=07", "01+05=06", "00+04=04", "01+08=09", "00+02=02", "01+88=89", "00+00=00", "02+88=90", "00+08=08", "08+88=96", "00+88=88", "impossible", "impossible", "impossible", "impossible", "impossible", "impossible"};
    int n; scanf("%d",&n);
    printf("%s",arr[n]);
}
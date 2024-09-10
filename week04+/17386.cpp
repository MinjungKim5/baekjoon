// https://www.acmicpc.net/problem/17386
// 선분 교차 1

// 문제
// 2차원 좌표 평면 위의 두 선분 L1, L2가 주어졌을 때, 두 선분이 교차하는지 아닌지 구해보자.
// L1의 양 끝 점은 (x1, y1), (x2, y2), L2의 양 끝 점은 (x3, y3), (x4, y4)이다.

// 입력
// 첫째 줄에 L1의 양 끝 점 x1, y1, x2, y2가, 둘째 줄에 L2의 양 끝 점 x3, y3, x4, y4가 주어진다.
//세 점이 일직선 위에 있는 경우는 없다.

// 출력
// L1과 L2가 교차하면 1, 아니면 0을 출력한다.

// 제한
// -1,000,000 ≤ x1, y1, x2, y2, x3, y3, x4, y4 ≤ 1,000,000
// x1, y1, x2, y2, x3, y3, x4, y4는 정수
// 선분의 길이는 0보다 크다.
// 예제 입력 1 
// 1 1 5 5
// 1 5 5 1
// 예제 출력 1 
// 1
// 예제 입력 2 
// 1 1 5 5
// 6 10 10 6
// 예제 출력 2 
// 0

#include <iostream>
#include <cmath>
using namespace std;
int main () {
//////////////////////////////////////////
double inputs[8];
for (int i = 0; i < 8; i++) cin >> inputs[i];
// 1번 선분
double x1, y1, x2, y2;
if (inputs[0] > inputs[2]) {
    x1 = inputs[2]; y1 = inputs[3];
    x2 = inputs[0]; y2 = inputs[1];
}
else {
    x2 = inputs[2]; y2 = inputs[3];
    x1 = inputs[0]; y1 = inputs[1];
}

// 2번 선분
double x3, y3, x4, y4;
if (inputs[4] > inputs[6]) {
    x3 = inputs[6]; y3 = inputs[7];
    x4 = inputs[4]; y4 = inputs[5];
}
else {
    x4 = inputs[6]; y4 = inputs[7];
    x3 = inputs[4]; y3 = inputs[5];
}

// case1: 평행
if ((x2-x1)*(y4-y3) == (x4-x3)*(y2-y1)) {cout << 0; return 0;}

// case2: 수직
if(x1 == x2) {
    if (x3 < x1 && x1 <x4) {
        if (min<double>((x4-x3)*y1,(x4-x3)*y2) < (y4-y3)*x1+x4*y3-x3*y4 &&
        (y4-y3)*x1+x4*y3-x3*y4 < max<double>((x4-x3)*y1,(x4-x3)*y2)) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}

if(x3 == x4) {
    if (x1 < x3 && x3 < x2) {
        if (min<double>((x2-x1)*y3,(x2-x1)*y4) < (y2-y1)*x3+x2*y1-x1*y2 &&
        (y2-y1)*x3+x2*y1-x1*y2 < max<double>((x2-x1)*y3,(x2-x1)*y4)) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}

double x = ((x4*y3-x3*y4)/(x4-x3)-(x2*y1-x1*y2)/(x2-x1))/((y2-y1)/(x2-x1)-(y4-y3)/(x4-x3));
if (max<double>(x1,x3) < x  && x < min<double>(x2,x4)) {
    cout << 1;
}
else cout << 0;
//////////////////////////////////////////
return 0;}
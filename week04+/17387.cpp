// https://www.acmicpc.net/problem/17387
// 선분 교차 2

// 문제
// 2차원 좌표 평면 위의 두 선분 L1, L2가 주어졌을 때, 두 선분이 교차하는지 아닌지 구해보자.
// 한 선분의 끝 점이 다른 선분이나 끝 점 위에 있는 것도 교차하는 것이다.
// L1의 양 끝 점은 (x1, y1), (x2, y2), L2의 양 끝 점은 (x3, y3), (x4, y4)이다.

// 입력
// 첫째 줄에 L1의 양 끝 점 x1, y1, x2, y2가, 둘째 줄에 L2의 양 끝 점 x3, y3, x4, y4가 주어진다.

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
// 예제 입력 3 
// 1 1 5 5
// 5 5 1 1
// 예제 출력 3 
// 1
// 예제 입력 4 
// 1 1 5 5
// 3 3 5 5
// 예제 출력 4 
// 1
// 예제 입력 5 
// 1 1 5 5
// 3 3 1 3
// 예제 출력 5 
// 1
// 예제 입력 6 
// 1 1 5 5
// 5 5 9 9
// 예제 출력 6 
// 1
// 예제 입력 7 
// 1 1 5 5
// 6 6 9 9
// 예제 출력 7 
// 0
// 예제 입력 8 
// 1 1 5 5
// 5 5 1 5
// 예제 출력 8 
// 1
// 예제 입력 9 
// 1 1 5 5
// 6 6 1 5
// 예제 출력 9 
// 0

#include <iostream>
#include <cmath>
using namespace std;
int main () {
//////////////////////////////////////////
long long inputs[8];
for (int i = 0; i < 8; i++) cin >> inputs[i];
// 1번 선분
long long x1, y1, x2, y2;
if (inputs[0] > inputs[2]) {
    x1 = inputs[2]; y1 = inputs[3];
    x2 = inputs[0]; y2 = inputs[1];
}
else {
    x2 = inputs[2]; y2 = inputs[3];
    x1 = inputs[0]; y1 = inputs[1];
}

// 2번 선분
long long x3, y3, x4, y4;
if (inputs[4] > inputs[6]) {
    x3 = inputs[6]; y3 = inputs[7];
    x4 = inputs[4]; y4 = inputs[5];
}
else {
    x4 = inputs[6]; y4 = inputs[7];
    x3 = inputs[4]; y3 = inputs[5];
}

long long y1min = min<long long>(y1, y2);
long long y2max = max<long long>(y1, y2);
long long y3min = min<long long>(y3, y4);
long long y4max = max<long long>(y3, y4);

// case0: 둘다 y축 방향
if (x1==x2 && x3==x4) {
    if (x1!=x3) cout << 0;
    else if ((y3min<=y1 && y1<=y4max) || (y3min<=y2 && y2<=y4max) || (y1min<=y3 && y3<=y2max) || (y1min<=y4 && y4<=y2max)) cout << 1;
    else cout << 0;
    return 0;
}

// case1: 둘중 하나만 y축 방향 -> 무조건 교차하는데 그 y좌표가 범위 내인지 확인
if(x1 == x2) {
    if (x3 <= x1 && x1 <= x4) {
        long long crossy = (x1*y4-x1*y3+x4*y3-x3*y4);
        if ((x4>x3) && y1min*(x4-x3)<= crossy && crossy <= y2max*(x4-x3)) cout << 1;
        else if ((x4<x3) && y2max*(x4-x3)<= crossy && crossy <= y1min*(x4-x3)) cout << 1;
        else cout << 9;
    }
    else cout << 0;
    return 0;
}

if(x3 == x4) {
    if (x1 <= x3 && x3 <= x2) {
        long long crossy = (x3*y2-x3*y1+x2*y1-x1*y2);
        if ((x2>x1) && y3min*(x2-x1)<= crossy && crossy <= y4max*(x2-x1)) cout << 1;
        else if ((x2<x1) && y4max*(x2-x1)<= crossy && crossy <= y3min*(x2-x1)) cout << 1;
        else cout << 9;
    }
    else cout << 0;
    return 0;
}

// case2: 평행
if ((x2-x1)*(y4-y3) == (x4-x3)*(y2-y1)) {
    // 절편 확인
    if ((x2*y1-x1*y2)*(x4-x3) != (x4*y3-x3*y4)*(x2-x1)) {cout << 0; return 0;}
    // 범위 확인
    if ((x3<=x1 && x1<=x4) || (x3<=x2 && x2<=x4) || (x1<=x3 && x3<=x2) || (x1<=x4 && x4<=x1)) cout << 1;
    else cout << 0;
    return 0;
}

// case3. 어디선가 크로스됨 -> 교점의 x좌표가 포함되는지 확인
long long x = ((x4*y3-x3*y4)*(x2-x1)-(x2*y1-x1*y2)*(x4-x3));
if ((y2-y1)*(x4-x3)-(y4-y3)*(x2-x1) > 0) {
    if (max<long long>(x1,x3)*((y2-y1)*(x4-x3)-(y4-y3)*(x2-x1)) <= x  &&
        x <= min<long long>(x2,x4)*((y2-y1)*(x4-x3)-(y4-y3)*(x2-x1))) {
        cout << 1;
    }
    else cout << 0;
}
else {
    if (max<long long>(x1,x3)*((y2-y1)*(x4-x3)-(y4-y3)*(x2-x1)) >= x  &&
        x >= min<long long>(x2,x4)*((y2-y1)*(x4-x3)-(y4-y3)*(x2-x1))) {
        cout << 1;
    }
    else cout << 0;
}
//////////////////////////////////////////
return 0;}
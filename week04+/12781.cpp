// https://www.acmicpc.net/problem/12781
// PIZZA ALVOLOC

// 문제
// 도윤이는 친구 3명과 함께 시험이 끝난 기념으로 도윤이의 집에서 놀기로 했다.
// 갑자기 배가 고파진 도윤이는 근처 맛 집인 PIZZA ALVOLOC에서 피자를 시켜먹기로 했다.
// 이 곳의 피자는 특이하게도, 보통 피자와 다르게 피자의 모양이 항상 볼록 다각형이다. 도윤이와 친구들은 피자를 네 등분해서 나눠먹기로 했다.
// 어떻게 나눌지 고민을 하던 중에 도윤이는 피자를 다음과 같이 나누기로 했다.
// 한 명씩 피자의 가장자리의 한 점을 선택한다. (같은 점을 선택하지 않는다.)
// 선택한 순서대로 첫 번째 점과 두 번째 점을 이어 선분을 만들고 세 번째 점과 네 번째 점을 이은 선분을 만든다.
// 만들어진 두 선분을 따라 피자를 자른다.
// 도윤이와 친구들은 잘라진 피자의 크기에 상관없이 네 조각으로만 나눠지면 먹기로 했다. 만약 네 조각으로 나눠지지 않는다면 도윤이와 친구들은 피자를 두고 싸우게 된다.
// 예를 들어 그림1의 경우에는 두 선분에 의해 피자가 네 조각으로 나뉘게 된다. 하지만 그림2의 경우에는 두 선분에 의해 피자가 세 조각으로 나뉘게 된다. 
// 도윤이와 친구들이 사이 좋게 피자를 나누어 먹을 수 있는지 알아보는 프로그램을 만들어 보자!

// 입력
// 입력의 첫 줄에는 도윤이와 친구들이 선택한 점의 좌표 x, y(-10,000 ≤ x, y ≤ 10,000)가 순서대로 4개 주어진다. x, y값은 항상 정수이다.

// 출력
// 주어진 4개의 점으로 도윤이가 친구들과 사이좋게 피자를 나눠 먹을 수 있으면 1, 그렇지 않으면 0을 출력한다.

// 예제 입력 1 
// 0 0 6 2 5 -4 2 2
// 예제 출력 1 
// 1
// 예제 입력 2 
// -1 -5 6 3 1 10 -4 -1
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
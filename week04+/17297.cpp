// https://www.acmicpc.net/problem/17297
// Messi Gimossi

// 문제
// 메시는 축구 선수이다. 메시는 기분이 좋다.
// messi(1): Messi
// messi(2)​​: Messi Gimossi
// messi(3)​​​​​​: Messi Gimossi Messi
// messi(4): Messi Gimossi Messi Messi Gimossi
// messi(5): Messi Gimossi Messi Messi Gimossi Messi Gimossi Messi
// 메시의 외침은 피보나치 수열과 유사하게 정의된다. messi(N)은 messi(N-1), 공백, messi(N-2)을 차례로 이어붙여서 만든 문자열이다.
// 욱제는 N이 충분히 클 때, messi(N)의 M번째 글자가 뭔지 궁금해졌다.

// 입력
// 정수 M이 주어진다. (1 ≤ M ≤ 2^30-1)

// 출력
// N이 충분히 클 때, messi(N)의 M번째 글자가 공백(' ')이 아닐 경우에는 그 글자를 출력한다.
// M번째 글자가 공백(' ')일 경우에는 Messi Messi Gimossi를 출력한다.
// 정답은 대소문자를 구분하므로 출력에 주의한다.

// 예제 입력 1 
// 1
// 예제 출력 1 
// M
// 예제 입력 2 
// 20
// 예제 출력 2 
// Messi Messi Gimossi
// 예제 입력 3 
// 1073741823
// 예제 출력 3 
// G

#include <iostream>
#include <vector>
using namespace std;

int main() {
///////////////////////////////////////////
vector<string> stringTable = {"x","M","e","s","s","i","Messi Messi Gimossi","G","i","m","o","s","s","i","Messi Messi Gimossi"};
int m; cin >> m;
if (m <= 14) {cout << stringTable[m]; return 0;}
vector<int> messiTable = {6,14};
int i = 1;
while (true) {
    int num = messiTable[i] + messiTable[i-1];
    messiTable.push_back(num);
    if (num >= m) break;
    i++;
}
while (m > 14) {
    m-=messiTable[i];
    while (messiTable[i] >= m) i--;
}
cout << stringTable[m];
///////////////////////////////////////////
return 0;}
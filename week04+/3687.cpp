// https://www.acmicpc.net/problem/3687
// 성냥개비

// 문제
// 성냥개비는 숫자를 나타내기에 아주 이상적인 도구이다. 보통 십진수를 성냥개비로 표현하는 방법은 다음과 같다.
// 성냥개비의 개수가 주어졌을 때, 성냥개비를 모두 사용해서 만들 수 있는 가장 작은 수와 큰 수를 찾는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 최대 100개 이다.
// 각 테스트 케이스는 한 줄로 이루어져 있고, 성냥개비의 개수 n이 주어진다. (2 ≤ n ≤ 100)

// 출력
// 각 테스트 케이스에 대해서 입력으로 주어진 성냥개비를 모두 사용해서 만들 수 있는 가장 작은 수와 가장 큰 수를 출력한다.
// 두 숫자는 모두 양수이어야 하고, 숫자는 0으로 시작할 수 없다. 

// 예제 입력 1 
// 4
// 3
// 6
// 7
// 15
// 예제 출력 1 
// 7 7
// 6 111
// 8 711
// 108 7111111

#include <iostream>
using namespace std;

void sngb(int num) {
    string maxstr = "";
    if (num%2) {
        maxstr += "7";
    } else {
        maxstr += "1";
    }
    for (int i = 1; i < num/2; i++) {
        maxstr += "1";
    }

    string nums[14] = {"0","0","1","7","4","2","6","8","10","18","22","20","28","68"};
    if (num < 14) {cout << nums[num] << " " << maxstr << "\n"; return;}
    string minstr = "";
    while (num > 13) {
        minstr = "8"+minstr;
        num -= 7;
    }
    if (num == 10) {minstr[0] = '0'; minstr = "20" + minstr;}
    else minstr = nums[num] + minstr;
    
    cout << minstr << " " << maxstr << "\n";
}

int main() {
    int testcase; cin >> testcase;
    for (int t = 0; t < testcase; t++) {
        int num; cin >> num;
        sngb(num);
    }
    return 0;
}
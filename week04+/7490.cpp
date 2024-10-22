// https://www.acmicpc.net/problem/7490
// 0 만들기

// 문제
// 1부터 N까지의 수를 오름차순으로 쓴 수열 1 2 3 ... N을 생각하자.
// 그리고 '+'나 '-', 또는 ' '(공백)을 숫자 사이에 삽입하자(+는 더하기, -는 빼기, 공백은 숫자를 이어 붙이는 것을 뜻한다).
// 이렇게 만든 수식의 값을 계산하고 그 결과가 0이 될 수 있는지를 살피자.
// N이 주어졌을 때 수식의 결과가 0이 되는 모든 수식을 찾는 프로그램을 작성하라.

// 입력
// 첫 번째 줄에 테스트 케이스의 개수가 주어진다(<10).
// 각 테스트 케이스엔 자연수 N이 주어진다(3 <= N <= 9).

// 출력
// 각 테스트 케이스에 대해 ASCII 순서에 따라 결과가 0이 되는 모든 수식을 출력한다.
// 각 테스트 케이스의 결과는 한 줄을 띄워 구분한다.

// 예제 입력 1 
// 2
// 3
// 7
// 예제 출력 1 
// 1+2-3

// 1+2-3+4-5-6+7
// 1+2-3-4+5+6-7
// 1-2 3+4+5+6+7
// 1-2 3-4 5+6 7
// 1-2+3+4-5+6-7
// 1-2-3-4-5+6+7

#include <iostream>
#include <vector>
using namespace std;

void check(int limitnum, vector<int> oper, int total) {
    int curr = oper.size();
    if (oper.back()==0){
        int operBefore = oper[curr-2];
        if (operBefore == 0) return;
        total += operBefore*(10*curr-9);
    }
    else total = total + oper.back()*curr;

    if (limitnum == oper.size()) {
        if (total) return;
        for (int n = 1; n <= limitnum; n++) {
            cout << n;
            switch (oper[n])
            {
            case 0:
                cout << " ";
                break;
            case 1:
                cout << "+";
                break;
            case -1:
                cout << "-";
                break;
            default:
                break;
            }
        }
        cout << "\n";
        return;    
    }
    oper.push_back(0);
    check(limitnum,oper,total);
    oper.pop_back();
    oper.push_back(1);
    check(limitnum,oper,total);
    oper.pop_back();
    oper.push_back(-1);
    check(limitnum,oper,total);
}

int main() {
/////////////////////////////////////
int testcase; cin >> testcase;
for (int t = 0; t < testcase; t++) {
    int num; cin >> num;
    vector<int> oper = {1};
    check(num,oper,0);
    cout << "\n";
}
/////////////////////////////////////
return 0;}
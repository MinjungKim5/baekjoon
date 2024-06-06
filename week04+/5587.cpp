// https://www.acmicpc.net/problem/5587
// 카드 캡터 상근이

// 문제
// 다음과 같은 카드게임이 BOJ 학교에서 유행하고 있다.
// 1에서 2n까지의 정수가 쓰여진 총 2n개의 카드를 사용한다. 카드를 2명이 n장씩 나눠가진다.
// 다음 규칙에 따라 교대로 카드를 1장씩 낸다.
// 놓여진 카드가 없다면 원하는 카드를 낼 수 있다. 놓여진 카드가 있다면 마지막에 나온 카드보다 큰 숫자가 적힌 카드를 낼 수 있다.
// 낼 카드가 없는 경우 상대의 차례가 된다. 이때, 자리에 나와있는 카드는 없어진다. 게임은 카드가 아무 것도 놓여있지 않은 상태에서 시작한다.
// 둘 중 한 명이라도 카드를 모두 사용하면 게임이 종료된다. 게임 종료시 상대방이 가지고 있는 카드의 수를 점수로 획득한다.
// 상근이와 근상이는 이 게임에서 맞붙게 됐다. 게임은 상근이의 차례에서 시작하며, 두 사람은 각자 낼 수 있는 카드 중 반드시 가장 작은 숫자가 적힌 카드를 내기로 하였다.
// 카드 캡터인 상근이는 게임의 결과를 미리 예상해서 질 것 같은 게임은 피하려고 한다. 배부되는 카드가 주어졌을 때, 상근이와 근상이의 점수를 출력하는 프로그램을 작성하자.

// 입력
// 1번째 줄에는 n이 주어진다. (1 ≤ n ≤ 100)
// 이후 n개의 줄에 상근이에게 주어지는 각 카드에 적힌 수가 주어진다. 즉, 1~2n중 나머지 카드는 근상이에게 주어진다.

// 출력
// 1번째 줄에 상근이의 점수를 출력하고, 2번째 줄에 근상이의 점수를 출력한다.

// 예제 입력 1 
// 5
// 1
// 7
// 9
// 6
// 10
// 예제 출력 1 
// 3
// 0
// 예제 입력 2 
// 10
// 8
// 7
// 14
// 18
// 4
// 11
// 3
// 17
// 5
// 19
// 예제 출력 2 
// 2
// 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
////////////////////////////////
int n_of_deck;
cin >> n_of_deck;
vector<int> ks(2*n_of_deck);
for (int i = 0; i < 2*n_of_deck; i++) ks[i] = i+1;
vector<int> sk;
for (int d = 0; d < n_of_deck; d++) {
    int draw;
    cin >> draw;
    sk.push_back(draw);
    for (int i = 0; i < ks.size(); i++) {
        if (ks[i] == draw) {
            ks.erase(ks.begin()+i);
            break;
        }
    }
}
sort(sk.begin(), sk.end());

// for (int k = 0; k < n_of_deck; k++) cout << sk[k] << " ";
// cout << endl;
// for (int k = 0; k < n_of_deck; k++) cout << ks[k] << " ";
// cout << endl;

int table = 0;
while (!ks.empty() && !sk.empty()) {
    // sk turn
    int sk_put = 0;
    for (int i = 0; i < sk.size(); i++) {
        if (sk[i] > table) {
            sk_put = sk[i];
            sk.erase(sk.begin()+i);
            break;
        }
    }
    // cout << sk_put << " ";
    table = sk_put;
    if (sk.empty()) break;
    //ks turn
    int ks_put = 0;
    for (int i = 0; i < ks.size(); i++) {
        if (ks[i] > table) {
            ks_put = ks[i];
            ks.erase(ks.begin()+i);
            break;        
        }
    }
    // cout << ks_put << endl;
    table = ks_put;
}
cout << ks.size() << endl << sk.size();

////////////////////////////////
return 0;}
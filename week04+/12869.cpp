// https://www.acmicpc.net/problem/12869
// 뮤탈리스크

// 문제
// 수빈이는 강호와 함께 스타크래프트 게임을 하고 있다. 수빈이는 뮤탈리스크 1개가 남아있고, 강호는 SCV N개가 남아있다.
// 각각의 SCV는 남아있는 체력이 주어져있으며, 뮤탈리스크를 공격할 수는 없다. 즉, 이 게임은 수빈이가 이겼다는 것이다.
// 뮤탈리스크가 공격을 할 때, 한 번에 세 개의 SCV를 공격할 수 있다.
// 첫 번째로 공격받는 SCV는 체력 9를 잃는다.
// 두 번째로 공격받는 SCV는 체력 3을 잃는다.
// 세 번째로 공격받는 SCV는 체력 1을 잃는다.
// SCV의 체력이 0 또는 그 이하가 되어버리면, SCV는 그 즉시 파괴된다. 한 번의 공격에서 같은 SCV를 여러 번 공격할 수는 없다.
// 남아있는 SCV의 체력이 주어졌을 때, 모든 SCV를 파괴하기 위해 공격해야 하는 횟수의 최솟값을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 SCV의 수 N (1 ≤ N ≤ 3)이 주어진다. 둘째 줄에는 SCV N개의 체력이 주어진다. 체력은 60보다 작거나 같은 자연수이다.

// 출력
// 첫째 줄에 모든 SCV를 파괴하기 위한 공격 횟수의 최솟값을 출력한다.

// 예제 입력 1 
// 3
// 12 10 4
// 예제 출력 1 
// 2
// 예제 입력 2 
// 3
// 54 18 6
// 예제 출력 2 
// 6
// 예제 입력 3 
// 1
// 60
// 예제 출력 3 
// 7
// 예제 입력 4 
// 3
// 1 1 1
// 예제 출력 4 
// 1
// 예제 입력 5 
// 2
// 60 40
// 예제 출력 5 
// 9

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dptable(61*61*61+1,-1);
int attack(vector<int> scvs) {
    sort(scvs.begin(), scvs.end(), greater<int>());
    for (int i = 0; i < 3; i++) {
        if (scvs[i] < 0) scvs[i] = 0;
    }
    int sum = scvs[0]*3721+scvs[1]*61+scvs[2];
    if (dptable[sum] == -1) {
        int minval = 9999;
        vector<int> results;
        results.push_back(attack({scvs[0]-9,scvs[1]-3,scvs[2]-1}));
        results.push_back(attack({scvs[0]-9,scvs[1]-1,scvs[2]-3}));
        results.push_back(attack({scvs[0]-3,scvs[1]-9,scvs[2]-1}));
        results.push_back(attack({scvs[0]-3,scvs[1]-1,scvs[2]-9}));
        results.push_back(attack({scvs[0]-1,scvs[1]-3,scvs[2]-9}));
        results.push_back(attack({scvs[0]-1,scvs[1]-9,scvs[2]-3}));
        for (int res: results){
            if (minval > res) minval = res;
        }
        dptable[sum] = minval+1;
    }
    return dptable[sum];
}
int main() {
/////////////////////////////////////////
dptable[0] = 0;
vector<int> scvs(3,0);
int n; cin >> n;
for (int i = 0; i < n; i++) {
    cin >> scvs[i];
}
for (int i = 1; i <= 9; i++) {
    for (int j = 0; j <= 3 && j <= i; j++) {
        for (int k = 0; k <= 1 && k <= j; k++) {
            dptable[i*3721+j*61+k] = 1;
        }
    }
}
cout << attack(scvs);
/////////////////////////////////////////
return 0;}
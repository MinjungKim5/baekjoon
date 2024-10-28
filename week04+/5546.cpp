// https://www.acmicpc.net/problem/5546
// 파스타

// 문제
// 상근이는 매일 저녁으로 파스타를 만들어 먹는다. 상근이가 만들 수 있는 파스타는 총 세 종류로 토마토 소스, 크림 소스, 바질 소스이다.
// 상근이는 앞으로 N일 동안 먹을 파스타를 계획하려고 한다. 매일 매일 세 종류의 파스타 중 한 종류를 선택할 것이다.
// 하지만, 같은 파스타를 계속해서 먹으면 질려버릴 수 있기 때문에, 3일 이상 연속해서 같은 파스타를 먹지 않는다.
// 또, N일 중 K일에 먹을 파스타는 미리 정해두었다.
// N과 K일에 먹을 파스타가 주어졌을 때, 가능한 계획의 수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N과 K가 주어진다. (3 ≤ N ≤ 100, 1 ≤ K ≤ N)
// 둘째 줄부터 K개 줄에는, 미리 파스타를 정해놓은 날의 정보가 주어진다.
// 이 정보는 Ai Bi와 같은 형식이며, Ai일에 먹을 파스타는 Bi라는 뜻이다.
// 이때, Bi = 1이면 토마토 소스, 2이면 크림 소스, 3이면 바질 소스이다. Ai는 모두 다르다.

// 출력
// 상근이가 세울 수 있는 계획의 수를 10000으로 나눈 나머지를 출력한다.

// 예제 입력 1 
// 5 3
// 3 1
// 1 1
// 4 2
// 예제 출력 1 
// 6
// 예제 입력 2 
// 20 5
// 10 2
// 4 3
// 12 1
// 13 2
// 9 1
// 예제 출력 2 
// 2640

#include <iostream>
#include <vector>
using namespace std;

int main() {
//////////////////////////////////////////
int n, kOfFixed; cin >> n >> kOfFixed;
vector<bool> fixed(n+1,false);
vector<vector<int>> bitmap(n+1,vector<int>(6,0));
for (int k = 0; k < kOfFixed; k++) {
    int day, kind; cin >> day >> kind;
    fixed[day] = true;
    bitmap[day][kind-1] = 1;
    bitmap[day][kind+2] = 1;
}

vector<vector<long long>> dptable(n+1, vector<long long>(6,0));
dptable[0] = {0,0,0,0,0,0};
dptable[1] = {1,1,1,0,0,0};
if (fixed[1]) {
    for (int i = 0; i < 6; i++) dptable[1][i] = dptable[1][i]*bitmap[1][i];
}
for (int d = 2; d <= n; d++) {
    for (int i = 0; i < 3; i++) {
        dptable[d][i] = (dptable[d-1][(i+1)%3]+dptable[d-1][(i+2)%3]+dptable[d-1][(i+1)%3+3]+dptable[d-1][(i+2)%3+3])%10000;
    }
    for (int i = 3; i < 6; i++) {
        dptable[d][i] = dptable[d-1][i-3];
    }
    if (fixed[d]) {
        for (int i = 0; i < 6; i++) dptable[d][i] = dptable[d][i]*bitmap[d][i];
    }
}
int res = 0;
for (int i = 0; i < 6; i++) {
    res += dptable[n][i];
}
cout << res%10000;
//////////////////////////////////////////
return 0;}
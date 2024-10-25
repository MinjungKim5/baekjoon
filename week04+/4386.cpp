// https://www.acmicpc.net/problem/4386
// 별자리 만들기

// 문제
// 도현이는 우주의 신이다. 이제 도현이는 아무렇게나 널브러져 있는 n개의 별들을 이어서 별자리를 하나 만들 것이다.
// 별자리의 조건은 다음과 같다.
// 별자리를 이루는 선은 서로 다른 두 별을 일직선으로 이은 형태이다.
// 모든 별들은 별자리 위의 선을 통해 서로 직/간접적으로 이어져 있어야 한다.
// 별들이 2차원 평면 위에 놓여 있다. 선을 하나 이을 때마다 두 별 사이의 거리만큼의 비용이 든다고 할 때, 별자리를 만드는 최소 비용을 구하시오.

// 입력
// 첫째 줄에 별의 개수 n이 주어진다. (1 ≤ n ≤ 100)
// 둘째 줄부터 n개의 줄에 걸쳐 각 별의 x, y좌표가 실수 형태로 주어지며, 최대 소수점 둘째자리까지 주어진다.
// 좌표는 1000을 넘지 않는 양의 실수이다.

// 출력
// 첫째 줄에 정답을 출력한다. 절대/상대 오차는 10-2까지 허용한다.

// 예제 입력 1 
// 3
// 1.0 1.0
// 2.0 2.0
// 2.0 4.0
// 예제 출력 1 
// 3.41

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> flags;

int findUnion(int a) {
    if (flags[a] == a) return a;
    int flag = findUnion(flags[a]);
    flags[a] = flag;
    return flag;
}

int main() {
////////////////////////////////////////
int nOfStars; cin >> nOfStars;
vector<pair<double,double>> stars(nOfStars,{0,0});
for (int n = 0; n < nOfStars; n++) {
    cin >> stars[n].first >> stars[n].second;
}
for (int i = 0; i < nOfStars; i++) flags.push_back(i);
priority_queue<pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>> > pq;
for (int i = 0; i < nOfStars-1; i++) {
    for (int j = i+1; j < nOfStars; j++) {
        int x1 = stars[i].first, y1 = stars[i].second;
        int x2 = stars[j].first, y2 = stars[j].second;
        double dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        pq.push({dist,{i,j}});
    }
}

double total = 0.0;
while(!pq.empty()) {
    double dist = pq.top().first;
    int s1 = pq.top().second.first;
    int s2 = pq.top().second.second;
    pq.pop();
    int a = findUnion(s1);
    int b = findUnion(s2);
    if (a!=b) {flags[b] = a; total += dist;}
}
cout << total;
////////////////////////////////////////
return 0;}
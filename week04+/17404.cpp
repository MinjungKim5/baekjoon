// https://www.acmicpc.net/problem/17404
// RGB거리 2

// 문제
// RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
// 집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때,
// 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.
// 1번 집의 색은 2번, N번 집의 색과 같지 않아야 한다.
// N번 집의 색은 N-1번, 1번 집의 색과 같지 않아야 한다.
// i(2 ≤ i ≤ N-1)번 집의 색은 i-1, i+1번 집의 색과 같지 않아야 한다.

// 입력
// 첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다.
// 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다.
// 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

// 출력
// 첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.

// 예제 입력 1 
// 3
// 26 40 83
// 49 60 57
// 13 89 99
// 예제 출력 1 
// 110
// 예제 입력 2 
// 3
// 1 100 100
// 100 1 100
// 100 100 1
// 예제 출력 2 
// 3

#include <iostream>
#include <vector>
using namespace std;

struct rgb {
    int r, g, b;
};

int main() {
////////////////////////////////////////////////
int nOfHouses; cin >> nOfHouses;
vector<rgb> costs(nOfHouses);
for (int n = 0; n < nOfHouses; n++) {
    cin >> costs[n].r >> costs[n].g >> costs[n].b;
}

int minval = 100000000;

vector<rgb> dp(nOfHouses);
dp[0]= {costs[0].r, 100000000, 100000000};
for (int i = 1; i < nOfHouses; i++) {
    dp[i].r = min<int>(dp[i-1].b, dp[i-1].g) + costs[i].r;
    dp[i].g = min<int>(dp[i-1].b, dp[i-1].r) + costs[i].g;
    dp[i].b = min<int>(dp[i-1].r, dp[i-1].g) + costs[i].b;
}
int redmin = min<int>(dp[nOfHouses-1].g, dp[nOfHouses-1].b);
if (minval > redmin) minval = redmin; 

dp[0]= {100000000, costs[0].g, 100000000};
for (int i = 1; i < nOfHouses; i++) {
    dp[i].r = min<int>(dp[i-1].b, dp[i-1].g) + costs[i].r;
    dp[i].g = min<int>(dp[i-1].b, dp[i-1].r) + costs[i].g;
    dp[i].b = min<int>(dp[i-1].r, dp[i-1].g) + costs[i].b;
}
int greenmin = min<int>(dp[nOfHouses-1].r, dp[nOfHouses-1].b);
if (minval > greenmin) minval = greenmin;

dp[0]= {100000000, 100000000, costs[0].b};
for (int i = 1; i < nOfHouses; i++) {
    dp[i].r = min<int>(dp[i-1].b, dp[i-1].g) + costs[i].r;
    dp[i].g = min<int>(dp[i-1].b, dp[i-1].r) + costs[i].g;
    dp[i].b = min<int>(dp[i-1].r, dp[i-1].g) + costs[i].b;
}
int bluemin = min<int>(dp[nOfHouses-1].g, dp[nOfHouses-1].r);
if (minval > bluemin) minval = bluemin; 
cout << minval;
////////////////////////////////////////////////
return 0;}
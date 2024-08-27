// https://www.acmicpc.net/problem/16117
// 실버런

// 문제
// 실버런(Silver Run)은 2차원 맵에서 캐릭터를 조종해서 최대한 많은 실버를 모으는 것이 목적인 모바일 게임이다.
// 실버런의 맵에는 실버 주머니들이 상하좌우로 일정한 간격을 두고 N행 M열의 직사각형 모양으로 배치되어 있으며,
// 각 주머니에는 정해진 개수만큼의 실버가 들어 있다.
// 편의상 상하좌우로 이웃한 실버 주머니 사이의 간격을 한 칸이라고 표현하며,
// 가장 왼쪽 위 주머니로부터 왼쪽으로 한 칸, 위로 한 칸 떨어진 위치로부터 아래로 x칸, 오른쪽으로 y칸 떨어진 위치를 (x, y)라고 표현한다.
// 즉 가장 왼쪽 위 주머니의 위치는 (1, 1), 가장 오른쪽 아래 주머니의 위치는 (N, M)이다.
// 게임이 시작되면 실버 주머니들은 1초당 한 칸의 일정한 속도로 왼쪽으로 움직이며,
// 유저는 캐릭터를 이동시키며 캐릭터와 부딪히는 실버 주머니에 든 실버를 획득하게 된다.
// 캐릭터와 주머니의 크기는 충분히 작아서, 실버를 획득하기 위해서는 캐릭터와 주머니의 위치가 정확히 일치해야 한다.
// 이 게임에서 가장 좋은 캐릭터는 16silver라는 캐릭터이다.
// 16silver는 임의의 위치에서 출발할 수 있으며(정수 좌표가 아니어도 된다!), 1초당 한 칸의 일정한 속도로 위, 아래 또는 오른쪽으로 이동할 수 있다.
// 그러나 제자리에 멈춰 있을 수는 없으며, 1초 단위로만 이동 명령을 내릴 수 있다.
// 예를 들어 "위로 2.5초 동안 이동"과 같은 명령은 내릴 수 없다.
// 맵이 주어질 때, 16silver 캐릭터를 이용해 모을 수 있는 실버의 최대 수량을 구하는 프로그램을 작성해 보자.

// 입력
// 첫 번째 줄에 맵에 있는 실버 주머니들이 이루는 직사각형의 행과 열 수를 나타내는 정수 N, M(1 ≤ N, M ≤ 1,000)이 공백을 사이에 두고 주어진다.
// 다음 N개의 줄에 걸쳐 각 줄에 M개의 정수가 주어진다.
// i번째 줄의 j번째 정수는 (i, j) 위치에 있는 실버 주머니에 들어 있는 실버의 양이며, 입력되는 모든 정수는 0 이상 100,000 이하이다.

// 출력
// 첫 번째 줄에 16silver 캐릭터로 모을 수 있는 실버의 최대 수량을 출력한다.

// 예제 입력 1 
// 4 5
// 10 10 15 45 33
// 99 10 27 44 96
// 11 99 97 98 75
// 13 47 67 55 0
// 예제 출력 1 
// 489
// 예제 입력 2 
// 5 5
// 10 14 13 12 11
// 10 22 16 12 83
// 95 44 56 98 71
// 10 97 96 25 99
// 10 10 47 38 12
// 예제 출력 2 
// 469

#include <vector>
#include <iostream>
using namespace std;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
///////////////////////////////////////////////////////////////////
int n,m; cin >> n >> m;
vector<vector<int>> silverMap(n+1, vector<int>(m+2, 0));
vector<vector<int>> runnerMap1(n+1, vector<int>(m+2, 0));
vector<vector<int>> runnerMap2(n+1, vector<int>(m+2, 0));
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        cin >> silverMap[i][j];
    }
}
if (n == 1) {
    int sum = 0;
    for (int j = 1; j <= m; j++) sum += silverMap[1][j];
    cout << sum;
    return 0;
}
// runnerMap11 채우기
for (int i = 1; i <= n; i++) {
    runnerMap1[i][1] = silverMap[i][1];
}
for (int j = 2; j <= m+1; j++) {
    runnerMap1[1][j] = max(runnerMap1[1][j-2]+silverMap[1][j-1],runnerMap1[2][j-1]) + silverMap[1][j];
    for (int i = 2; i < n; i++) {
        runnerMap1[i][j] = max(max(runnerMap1[i-1][j-1], runnerMap1[i+1][j-1]), runnerMap1[i][j-2]+silverMap[i][j-1]) + silverMap[i][j];
    }
    runnerMap1[n][j] = max(runnerMap1[n][j-2]+silverMap[n][j-1], runnerMap1[n-1][j-1]) + silverMap[n][j];
}

// runnerMap2 채우기
for (int j = 1; j <= m+1; j++) {
    runnerMap2[0][j] = runnerMap2[1][j-1] + silverMap[1][j];
    for (int i = 1; i < n; i++) {
        runnerMap2[i][j] = max(runnerMap2[i-1][j-1]+silverMap[i][j], runnerMap2[i+1][j-1]+silverMap[i+1][j]);
    }
    runnerMap2[n][j] = runnerMap2[n-1][j-1] + silverMap[n][j];
}

int maxval = 0;
for (int i = 0; i <= n; i++) {
    if (runnerMap1[i][m+1] > maxval) maxval = runnerMap1[i][m+1];
    if (runnerMap2[i][m+1] > maxval) maxval = runnerMap2[i][m+1];
}
cout << maxval;
///////////////////////////////////////////////////////////////////
return 0;}
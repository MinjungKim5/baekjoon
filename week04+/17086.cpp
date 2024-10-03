// https://www.acmicpc.net/problem/17086
// 아기상어 2

// 문제
// N×M 크기의 공간에 아기 상어 여러 마리가 있다. 공간은 1×1 크기의 정사각형 칸으로 나누어져 있다.
// 한 칸에는 아기 상어가 최대 1마리 존재한다.
// 어떤 칸의 안전 거리는 그 칸과 가장 거리가 가까운 아기 상어와의 거리이다.
// 두 칸의 거리는 하나의 칸에서 다른 칸으로 가기 위해서 지나야 하는 칸의 수이고, 이동은 인접한 8방향(대각선 포함)이 가능하다.
// 안전 거리가 가장 큰 칸을 구해보자. 

// 입력
// 첫째 줄에 공간의 크기 N과 M(2 ≤ N, M ≤ 50)이 주어진다.
// 둘째 줄부터 N개의 줄에 공간의 상태가 주어지며, 0은 빈 칸, 1은 아기 상어가 있는 칸이다.
// 빈 칸과 상어의 수가 각각 한 개 이상인 입력만 주어진다.

// 출력
// 첫째 줄에 안전 거리의 최댓값을 출력한다.

// 예제 입력 1 
// 5 4
// 0 0 1 0
// 0 0 0 0
// 1 0 0 0
// 0 0 0 0
// 0 0 0 1
// 예제 출력 1 
// 2
// 예제 입력 2 
// 7 4
// 0 0 0 1
// 0 1 0 0
// 0 0 0 0
// 0 0 0 1
// 0 0 0 0
// 0 1 0 0
// 0 0 0 1
// 예제 출력 2 
// 2

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> directions = {{-1,-1},{-1,1},{1,-1},{1,1},{-1,0},{1,0},{0,-1},{0,1}};
int bfs(vector<vector<int>>map, pair<int,int>cord) {
    if (map[cord.first][cord.second]) return 0;
    int v = map.size(), h = map[0].size();
    vector<vector<int>> visitmap(v, vector<int>(h, 10000000));
    queue<pair<int,int>> visitq;
    visitq.push(cord);
    visitmap[cord.first][cord.second] = 1;
    while(!visitq.empty()) {
        int y = visitq.front().first;
        int x = visitq.front().second;
        visitq.pop();
        for (int d = 0; d < 8; d++) {
            int newy = y + directions[d].first;
            int newx = x + directions[d].second;
            if (newy >= v || newy < 0 || newx >= h || newx < 0) continue;
            if (map[newy][newx] == 1) return visitmap[y][x];
            else if (visitmap[newy][newx] > visitmap[y][x]+1) {
                visitmap[newy][newx] = visitmap[y][x] + 1;
                visitq.push({newy,newx});
            }
        }
    }
    return 0;
}

int main() {
///////////////////////////////////////
int vertical, horizontal; cin >> vertical >> horizontal;
vector<vector<int>> map(vertical,vector<int>(horizontal,0));
for (int v = 0; v < vertical; v++) {
    for (int h = 0; h < horizontal; h++) {
        int shark = 0; cin >> shark;
        if (shark) map[v][h] = 1;
    }
}
int maxval = 0;
for (int v = 0; v < vertical; v++) {
    for (int h = 0; h < horizontal; h++) {
        int res = bfs(map, {v,h});
        if (res > maxval) maxval = res;
    }
}
cout << maxval;
///////////////////////////////////////
return 0;}
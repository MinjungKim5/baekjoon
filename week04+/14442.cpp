// https://www.acmicpc.net/problem/14442
// 벽 부수고 이동하기 2

// 문제
// N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다.
// 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다.
// 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.
// 만약에 이동하는 도중에 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 K개 까지 부수고 이동하여도 된다.
// 한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.
// 맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000), K(1 ≤ K ≤ 10)이 주어진다.
// 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

// 출력
// 첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.

// 예제 입력 1 
// 6 4 1
// 0100
// 1110
// 1000
// 0000
// 0111
// 0000
// 예제 출력 1 
// 15

// 예제 입력 2 
// 6 4 2
// 0100
// 1110
// 1000
// 0000
// 0111
// 0000
// 예제 출력 2 
// 9

// 예제 입력 3 
// 4 4 3
// 0111
// 1111
// 1111
// 1110
// 예제 출력 3 
// -1

#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    vector<pair<int,int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
    int vertical, horizontal, chance; cin >> vertical >> horizontal >> chance;
    vector<vector<int>> gmap(vertical, vector<int>(horizontal,0));
    vector<vector<vector<int>>> vmap(vertical, vector<vector<int>>(horizontal, vector<int>(chance+1, 200000000)));
    for (int i = 0; i < vertical; i++) {
        string inrow; cin >> inrow;
        for (int s = 0; s < horizontal; s++) {
            if (inrow[s] == '1') gmap[i][s] = 1;
        }
    }
    vmap[0][0][0] = 1;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()) {
        int cord = q.front().first;
        int k = q.front().second;
        int y = cord/10000;
        int x = cord%10000;
        if (y == vertical-1 && x == horizontal-1) {
            cout << vmap[y][x][k];
            return 0;
        }
        q.pop();
        for (int d = 0; d < 4; d++) {
            int newy = y+dir[d].first;
            int newx = x+dir[d].second;
            if (newy < 0 || newy >= vertical || newx < 0 || newx >= horizontal) continue;
            if (gmap[newy][newx] == 0) {
                int oldval = vmap[newy][newx][k];
                int newval = vmap[y][x][k] + 1;
                if (oldval > newval) {
                    for (int i = k; i <= chance; i++) {
                        vmap[newy][newx][i] = newval;
                    }
                    q.push({newy*10000+newx, k});
                }
            }
            else {
                if (k == chance) continue;
                int oldval = vmap[newy][newx][k+1];
                int newval = vmap[y][x][k] + 1;
                if (oldval > newval) {
                    for (int i = k+1; i <= chance;i++) {
                        vmap[newy][newx][i] = newval;
                    }
                    q.push({newy*10000+newx, k+1});
                }
            }
        }
    }
    cout << -1;
    return 0;
}
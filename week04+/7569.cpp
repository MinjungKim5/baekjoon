// https://www.acmicpc.net/problem/7569
// 토마토

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> dir = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
/////////////////////////////////////////////////////
int n,m,h; cin >> m >> n >> h;
vector<vector<vector<pair<int,int>>>> map(h, vector<vector<pair<int,int>>>(n, vector<pair<int,int>>(m,{0,0})));
queue<vector<int>> q;
int count = 0;
for (int k = 0; k < h; k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num; cin >> num;
            if (num == 1) q.push({k,i,j});
            if (num == 0) count++;
            map[k][i][j] = {num,0};
        }
    }
}
if (count == 0) {cout << 0 ; return 0;}
while (!q.empty()) {
    int z = q.front()[0];
    int y = q.front()[1];
    int x = q.front()[2];
    int round = map[z][y][x].second;
    q.pop();
    for (vector<int> d: dir) {
        int newz = z+d[0];
        int newy = y+d[1];
        int newx = x+d[2];
        if (newz < 0 || newy < 0 || newx < 0 || newz >= h || newy >= n || newx >= m) continue;
        if (map[newz][newy][newx].first == 0) {
            map[newz][newy][newx] = {1,round+1};
            count--;
            q.push({newz,newy,newx});
        }
        if (count == 0) {cout << round+1; return 0;}
    }
}
cout << -1;
/////////////////////////////////////////////////////
return 0;}
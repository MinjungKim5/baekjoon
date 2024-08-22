// https://www.acmicpc.net/problem/17267
// 상남자

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main() {
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
//////////////////////////////////////
int count = 1;
int n_of_rows,m_of_columns; cin >> n_of_rows >> m_of_columns;
int l, r; cin >> l >> r;
vector<vector<bool>> wall(n_of_rows, vector<bool>(m_of_columns,false));
vector<vector<pair<int,int>>> visit_state(n_of_rows, vector<pair<int,int>>(m_of_columns));
queue<pair<int,int>> q;
for (int n = 0; n < n_of_rows; n++) {
    string a; cin >> a;
    for (int m = 0; m < m_of_columns; m++) {
        if (a[m] != '0') wall[n][m] = true;
        if (a[m] == '2') {
            q.push({n,m});
            visit_state[n][m] = {l,r};
        }
    }
}

while (!q.empty()) {
    pair<int,int> cord = q.front(); q.pop();
    pair<int,int> s = visit_state[cord.first][cord.second];
    for (int yp = 1; yp < 1000; yp++) {
        if (cord.first+yp >= n_of_rows) break;
        if (wall[cord.first+yp][cord.second]) break;
        count += 1;
        wall[cord.first+yp][cord.second] = true;
        visit_state[cord.first+yp][cord.second] = s;
        q.push({cord.first+yp, cord.second});
    }
    for (int ym = 1; ym < 1000; ym++) {
        if (cord.first-ym < 0) break;
        if (wall[cord.first-ym][cord.second]) break;
        count += 1;
        wall[cord.first-ym][cord.second] = true;
        visit_state[cord.first-ym][cord.second] = s;
        q.push({cord.first-ym, cord.second});
    }
    if (s.first > 0 && cord.second > 0 && !wall[cord.first][cord.second-1]) {
        count += 1;
        wall[cord.first][cord.second-1] = true;
        visit_state[cord.first][cord.second-1] = {s.first-1, s.second};
        q.push({cord.first, cord.second-1});
    }
    if (s.second > 0 && cord.second < m_of_columns-1 && !wall[cord.first][cord.second+1]) {
        count += 1;
        wall[cord.first][cord.second+1] = true;
        visit_state[cord.first][cord.second+1] = {s.first, s.second-1};
        q.push({cord.first, cord.second+1});
    }
}
cout << count;
//////////////////////////////////////
return 0;}
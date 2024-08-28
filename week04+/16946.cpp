// https://www.acmicpc.net/problem/16946
// 벽 부수고 이동하기 4

// 문제
// N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다.
// 한 칸에서 다른 칸으로 이동하려면, 두 칸이 인접해야 한다. 두 칸이 변을 공유할 때, 인접하다고 한다.
// 각각의 벽에 대해서 다음을 구해보려고 한다.
// 벽을 부수고 이동할 수 있는 곳으로 변경한다.
// 그 위치에서 이동할 수 있는 칸의 개수를 세어본다.
// 한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.

// 입력
// 첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다.

// 출력
// 맵의 형태로 정답을 출력한다. 원래 빈 칸인 곳은 0을 출력하고, 벽인 곳은 이동할 수 있는 칸의 개수를 10으로 나눈 나머지를 출력한다.

// 예제 입력 1 
// 3 3
// 101
// 010
// 101
// 예제 출력 1 
// 303
// 050
// 303
// 예제 입력 2 
// 4 5
// 11001
// 00111
// 01010
// 10101
// 예제 출력 2 
// 46003
// 00732
// 06040
// 50403

#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//////////////////////////////////////////////
int vertical, horizontal; cin >> vertical >> horizontal;
vector<vector<int>> map1(vertical, vector<int>(horizontal, 0));
vector<vector<int>> map2(vertical, vector<int>(horizontal, 0));
for (int v = 0; v < vertical; v++) {
    string str; cin >> str;
    for (int h = 0; h < horizontal; h++) {
        map1[v][h] = str[h]-48;
    }
}

vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
// 0인 지점부터 BFS돌면서 union 및 count해줌
vector<int> unionCount = {0,0};
int uni = 1;
for (int v = 0; v < vertical; v++) {
    for (int h = 0; h < horizontal; h++) {
        if (map1[v][h] == 0) {
            uni += 1;
            int count = 1;
            queue<pair<int,int>> q;
            map1[v][h] = uni;
            q.push({v,h});
            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int newy = y+directions[d].first;
                    int newx = x+directions[d].second;
                    if (0 <= newy && newy < vertical && 0 <= newx && newx < horizontal && map1[newy][newx] == 0) {
                        count += 1;
                        map1[newy][newx] = uni;
                        q.push({newy,newx});
                    }
                }
            }
            unionCount.push_back(count);
        }
    }
}

// 1인 지점의 상하좌우에 어떤 유니언 있는지 확인해서 더한 값을 map2에 업데이트
for (int v = 0; v < vertical; v++) {
    for (int h = 0; h < horizontal; h++) {
        if (map1[v][h] == 1) {
            vector<int> uniSet;
            for (int d = 0; d < 4; d++) {
                int newy = v+directions[d].first;
                int newx = h+directions[d].second;
                if (0 <= newy && newy < vertical && 0 <= newx && newx < horizontal) {
                    bool check = true;
                    for (int i = 0; i < uniSet.size(); i++) {
                        if (uniSet[i] == map1[newy][newx]) {check = false; break;}
                    }
                    if (check) uniSet.push_back(map1[newy][newx]);
                }
            }
            int res = 1;
            for (int i = 0; i < uniSet.size(); i++) res += unionCount[uniSet[i]];
            map2[v][h] = res%10;
        }
    }
}
for (int v = 0; v < vertical; v++) {
    for (int h = 0; h < horizontal; h++) {
        cout << map2[v][h];
    }
    cout << "\n";
}

//////////////////////////////////////////////
return 0;}
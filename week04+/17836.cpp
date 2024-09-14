// https://www.acmicpc.net/problem/17836
// 공주님을 구해라!

// 문제
// 용사는 마왕이 숨겨놓은 공주님을 구하기 위해 (N, M) 크기의 성 입구 (1,1)으로 들어왔다. 마왕은 용사가 공주를 찾지 못하도록 성의 여러 군데 마법 벽을 세워놓았다.
// 용사는 현재의 가지고 있는 무기로는 마법 벽을 통과할 수 없으며, 마법 벽을 피해 (N, M) 위치에 있는 공주님을 구출해야만 한다.
// 마왕은 용사를 괴롭히기 위해 공주에게 저주를 걸었다. 저주에 걸린 공주는 T시간 이내로 용사를 만나지 못한다면 영원히 돌로 변하게 된다.
// 공주님을 구출하고 프러포즈 하고 싶은 용사는 반드시 T시간 내에 공주님이 있는 곳에 도달해야 한다. 용사는 한 칸을 이동하는 데 한 시간이 걸린다.
// 공주님이 있는 곳에 정확히 T시간만에 도달한 경우에도 구출할 수 있다. 용사는 상하좌우로 이동할 수 있다.
// 성에는 이전 용사가 사용하던 전설의 명검 "그람"이 숨겨져 있다. 용사가 그람을 구하면 마법의 벽이 있는 칸일지라도, 단숨에 벽을 부수고 그 공간으로 갈 수 있다.
// "그람"은 성의 어딘가에 반드시 한 개 존재하고, 용사는 그람이 있는 곳에 도착하면 바로 사용할 수 있다. 그람이 부술 수 있는 벽의 개수는 제한이 없다.
// 우리 모두 용사가 공주님을 안전하게 구출 할 수 있는지, 있다면 얼마나 빨리 구할 수 있는지 알아보자.

// 입력
// 첫 번째 줄에는 성의 크기인 N, M 그리고 공주에게 걸린 저주의 제한 시간인 정수 T가 주어진다. 첫 줄의 세 개의 수는 띄어쓰기로 구분된다. (3 ≤ N, M ≤ 100, 1 ≤ T ≤ 10000)

// 두 번째 줄부터 N+1번째 줄까지 성의 구조를 나타내는 M개의 수가 띄어쓰기로 구분되어 주어진다.
// 0은 빈 공간, 1은 마법의 벽, 2는 그람이 놓여있는 공간을 의미한다. (1,1)과 (N,M)은 0이다.

// 출력
// 용사가 제한 시간 T시간 이내에 공주에게 도달할 수 있다면, 공주에게 도달할 수 있는 최단 시간을 출력한다.

// 만약 용사가 공주를 T시간 이내에 구출할 수 없다면, "Fail"을 출력한다.

// 예제 입력 1 
// 6 6 16
// 0 0 0 0 1 1
// 0 0 0 0 0 2
// 1 1 1 0 1 0
// 0 0 0 0 0 0
// 0 1 1 1 1 1
// 0 0 0 0 0 0
// 예제 출력 1 
// 10

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main() {
//////////////////////////////////////////////
int vertical, horizontal, timelimit; cin >> vertical >> horizontal >> timelimit;
vector<vector<int>> mazeMap(vertical, vector<int>(horizontal));
vector<vector<int>> visitMap(vertical, vector<int>(horizontal, 100000));
pair<int,int> sword;
for (int v = 0; v < vertical; v++) {
    for (int h = 0; h < horizontal; h++) {
        int num; cin >> num;
        if (num == 2) {
            sword = {v,h};
            num = 0;
        }
        mazeMap[v][h] = num;
    }
}

queue<pair<int,int>> q;
q.push({0,0});
visitMap[0][0] = 0;
vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
while (!q.empty()) {
    int y = q.front().first, x = q.front().second;
    q.pop();
    for (int d = 0; d < 4; d++) {
        int newy = y + directions[d].first;
        int newx = x + directions[d].second;
        if (newy < 0 || newy >= vertical || newx < 0 || newx >= horizontal) continue;
        if (mazeMap[newy][newx] == 0 && visitMap[newy][newx] > visitMap[y][x] + 1) {
            visitMap[newy][newx] = visitMap[y][x] + 1;
            q.push({newy,newx});
        }
    }
}
int time = min<int>(visitMap[vertical-1][horizontal-1], visitMap[sword.first][sword.second]+ vertical + horizontal - 2 - sword.first - sword.second);
if (time <= timelimit) cout << time;
else cout << "Fail";
//////////////////////////////////////////////
return 0;}
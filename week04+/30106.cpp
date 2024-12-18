// https://www.acmicpc.net/problem/30106
// 현이의 로봇 청소기

// 문제
// 현이의 방은 매우 지저분하다! 현이는 선물로 로봇 청소기를 받았고, 귀찮은 청소를 맡기기로 했다.
// 로봇 청소기는 현이의 방을 1 X 1 크기의 정사각형으로 나누어져 있는 N X M 크기의 직사각형으로 인식한다.
// 로봇 청소기는 한 영역을 청소하고 나서 상, 하, 좌, 우로 인접한 영역 중 하나로 이동한다.
// 현이의 방은 오래되어 마루가 울퉁불퉁하고, 쓰레기도 눌러붙어 각 영역마다 높이가 조금씩 다르다.
// 로봇 청소기는 높이 차이가 K 초과인 두 영역 사이를 이동하면 고장이 날 수 있기 때문에, 높이 차이가 K 이하인 영역 사이에서만 이동한다.
// 현이는 외출하는 동안 로봇 청소기를 작동시키고 집에 돌아왔지만, 청소가 되지 않은 곳도 있는 것을 보고 실망했다.
// 결국 현이는 로봇 청소기의 위치를 직접 옮겨주기로 했다. 현이가 로봇 청소기를 직접 옮길 때는 아무 영역으로나 옮길 수 있다.
// 로봇 청소기를 켠 상태로 옮기면 위험하니 로봇 청소기를 끄고 옮긴 뒤에 다시 작동시킬 수 있다.
// 현이가 로봇 청소기를 최소 몇 번 작동시켜야 방의 모든 영역을 청소할 수 있을지 구해보자!

// 입력
// 첫 번째 줄에 자연수 N, M, K가 공백으로 구분되어 주어진다.
// 두 번째 줄부터 N+1번째 줄까지 각 영역의 높이를 나타내는 정수 M개가 공백으로 구분되어 주어진다.

// 출력
// 방의 모든 영역을 청소하기 위해 로봇 청소기를 작동시켜야 하는 최소 횟수를 출력한다.

// 제한
// 1 <= N, M <= 500
// 1 <= K <= 10^9
// 각 영역의 높이는 1 이상 10^9 이하이다.
// 예제 입력 1 
// 2 3 2
// 5 4 6
// 4 7 2
// 예제 출력 1 
// 3

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main() {
/////////////////////////////////////
vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
int vertical, horizontal, threshold; cin >> vertical >> horizontal >> threshold;
vector<vector<int>> map(vertical, vector<int>(horizontal, 0));
vector<vector<bool>> visited(vertical, vector<bool>(horizontal, false));
for (int v = 0; v < vertical; v++) {
    for (int h = 0; h < horizontal; h++) {
        cin >> map[v][h];
    }
}
int count = 0;
for (int v = 0; v < vertical; v++) {
    for (int h = 0; h < horizontal; h++) {
        if (visited[v][h]) continue;
        queue<pair<int,int>> q;
        q.push({v,h});
        visited[v][h] = true;
        count++;
        while(!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            int h = map[y][x];
            for (pair<int,int> d: dir) {
                int newy = y+d.first;
                int newx = x+d.second;
                if (newy < 0 || newy >= vertical || newx < 0 || newx >= horizontal) continue;
                if (visited[newy][newx]) continue;
                if (abs(h-map[newy][newx]) <= threshold) {
                    q.push({newy,newx});
                    visited[newy][newx] = true;
                }
            }
        }
    }
}
cout << count;
/////////////////////////////////////
return 0;}
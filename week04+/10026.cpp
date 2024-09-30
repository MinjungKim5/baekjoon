// https://www.acmicpc.net/problem/10026
// 적록색약

// 문제
// 적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.
// 크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다.
// 그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다.
// 또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다.
// (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)
// 예를 들어, 그림이 아래와 같은 경우에
// RRRBB
// GGBBB
// BBBRR
// BBRRR
// RRRRR
// 적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1)
// 하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)
// 그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100)
// 둘째 줄부터 N개 줄에는 그림이 주어진다.

// 출력
// 적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 공백으로 구분해 출력한다.

// 예제 입력 1 
// 5
// RRRBB
// GGBBB
// BBBRR
// BBRRR
// RRRRR
// 예제 출력 1 
// 4 3

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
//////////////////////////////////////////////
vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
int size; cin >> size;
vector<string> picture(size);
for (int s = 0; s < size; s++) {
    cin >> picture[s];
}

// 적록색약 아닌사람
int rgbCount = 0;
vector<vector<int>> rgbmap(size, vector<int>(size,0));
for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
        queue<pair<int,int>> rgbq;
        if (rgbmap[i][j] != 0) continue;
        rgbCount++;
        rgbmap[i][j] = rgbCount;
        rgbq.push({i,j});
        while (!rgbq.empty()) {
            int y = rgbq.front().first;
            int x = rgbq.front().second;
            rgbq.pop();
            for (int d = 0; d < 4; d++) {
                int newy = y + directions[d].first;
                int newx = x + directions[d].second;
                if (newy < 0 || newy >= size || newx < 0 || newx >= size) continue;
                if (rgbmap[newy][newx] != 0) continue;
                if (picture[y][x] == picture[newy][newx]) {
                    rgbq.push({newy,newx});
                    rgbmap[newy][newx] = rgbCount;
                }
            }
        }
    }
}

// 적록색약
int rbCount = 0;
vector<vector<int>> rbmap(size, vector<int>(size,0));
for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
        queue<pair<int,int>> rbq;
        if (rbmap[i][j] != 0) continue;
        rbCount++;
        rbmap[i][j] = rbCount;
        rbq.push({i,j});
        while (!rbq.empty()) {
            int y = rbq.front().first;
            int x = rbq.front().second;
            rbq.pop();
            for (int d = 0; d < 4; d++) {
                int newy = y + directions[d].first;
                int newx = x + directions[d].second;
                if (newy < 0 || newy >= size || newx < 0 || newx >= size) continue;
                if (rbmap[newy][newx] != 0) continue;
                char pix = picture[y][x], newpix = picture[newy][newx];
                if (((pix=='R' || pix=='G')&&(newpix=='R' || newpix=='G')) || (pix=='B'&&newpix=='B')) {
                    rbq.push({newy,newx});
                    rbmap[newy][newx] = rbCount;
                }
            }
        }
    }
}

cout << rgbCount << " " << rbCount;
//////////////////////////////////////////////
return 0;}
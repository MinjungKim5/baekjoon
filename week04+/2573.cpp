// https://www.acmicpc.net/problem/2573
// 빙산

// 문제
// 지구 온난화로 인하여 북극의 빙산이 녹고 있다. 빙산을 그림과 같이 2차원 배열에 표시한다고 하자.
// 빙산의 각 부분별 높이 정보는 배열의 각 칸에 양의 정수로 저장된다. 빙산 이외의 바다에 해당되는 칸에는 0이 저장된다.
// 그림 1에서 빈칸은 모두 0으로 채워져 있다고 생각한다.
 	 	 	 		 
//  	2	4	5	3	 	 
//  	3	 	2	5	2	 
//  	7	6	2	4	 	 
 	 	 	 	 	 	 
// 빙산의 높이는 바닷물에 많이 접해있는 부분에서 더 빨리 줄어들기 때문에,
// 배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다.
// 단, 각 칸에 저장된 높이는 0보다 더 줄어들지 않는다. 바닷물은 호수처럼 빙산에 둘러싸여 있을 수도 있다.
// 따라서 그림 1의 빙산은 일년후에 그림 2와 같이 변형된다.
// 그림 3은 그림 1의 빙산이 2년 후에 변한 모습을 보여준다.
// 2차원 배열에서 동서남북 방향으로 붙어있는 칸들은 서로 연결되어 있다고 말한다.
// 따라서 그림 2의 빙산은 한 덩어리이지만, 그림 3의 빙산은 세 덩어리로 분리되어 있다.
 	 	 	 	 	 	 
//  	 	2	4	1	 	 
//  	1	 	1	5	 	 
//  	5	4	1	2	 	 
 	 	 	 	 	 	 
// 그림 2
 	 	 	 	 	 	 
//  	 	 	3	 	 	 
//  	 	 	 	4	 	 
//  	3	2	 	 	 	 
 	 	 	 	 	 	 
// 그림 3

// 한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램을 작성하시오.
// 그림 1의 빙산에 대해서는 2가 답이다. 만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다.

// 입력
// 첫 줄에는 이차원 배열의 행의 개수와 열의 개수를 나타내는 두 정수 N과 M이 한 개의 빈칸을 사이에 두고 주어진다. N과 M은 3 이상 300 이하이다.
// 그 다음 N개의 줄에는 각 줄마다 배열의 각 행을 나타내는 M개의 정수가 한 개의 빈 칸을 사이에 두고 주어진다.
// 각 칸에 들어가는 값은 0 이상 10 이하이다. 배열에서 빙산이 차지하는 칸의 개수, 즉, 1 이상의 정수가 들어가는 칸의 개수는 10,000 개 이하이다.
// 배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다.

// 출력
// 첫 줄에 빙산이 분리되는 최초의 시간(년)을 출력한다. 만일 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다.

// 예제 입력 1 
// 5 7
// 0 0 0 0 0 0 0
// 0 2 4 5 3 0 0
// 0 3 0 2 5 2 0
// 0 7 6 2 4 0 0
// 0 0 0 0 0 0 0
// 예제 출력 1 
// 2

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
//////////////////////////////////////////////
vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
int vertical, horizontal; cin >> vertical >> horizontal;
vector<vector<int>> map(vertical,vector<int>(horizontal,0));
for (int v = 0; v < vertical; v++) {
    for (int h = 0; h < horizontal; h++) {
        cin >> map[v][h];
    }
}

int glacier = 1;
int year = 0;
while (glacier == 1) {
    vector<vector<int>> wmap(vertical, vector<int>(horizontal,0));
    queue<pair<int,int>> wq;
    for (int v = 0; v < vertical; v++) {
        for (int h = 0; h < horizontal; h++) {
            if (map[v][h] == 0 && wmap[v][h] == 0) {
                wq.push({v,h});
                wmap[v][h] = 1;
            }
            while (!wq.empty()) {
                int y = wq.front().first;
                int x = wq.front().second;
                wq.pop();
                for (int d = 0; d < 4; d++) {
                    int newy = y + directions[d].first;
                    int newx = x + directions[d].second;
                    if (newy < 0 || newy >= vertical || newx < 0 || newx >= horizontal) continue;
                    if (wmap[newy][newx]==1) continue;
                    if (wmap[newy][newx]==0 && map[newy][newx] == 0) {
                        wmap[newy][newx] = 1;
                        wq.push({newy,newx});
                    }
                    else if (map[newy][newx] > 0) {
                        wmap[newy][newx] = 2;
                        map[newy][newx]--;
                    }
                }
            }
        }
    }
    year++;

    vector<vector<bool>> gmap(vertical, vector<bool>(horizontal,false));
    glacier = 0;
    queue<pair<int,int>> gq;
    for (int v = 0; v < vertical; v++) {
        for (int h = 0; h < horizontal; h++) {
            if (map[v][h]!=0 && gmap[v][h] == false) {
                gq.push({v,h});
                glacier++;
            }
            while (!gq.empty()) {
                int y = gq.front().first;
                int x = gq.front().second;
                gq.pop();
                for (int d = 0; d < 4; d++) {
                    int newy = y+ directions[d].first;
                    int newx = x + directions[d].second;
                    if (newy < 0 || newy >= vertical || newx < 0 || newx >= horizontal) continue;
                    if (gmap[newy][newx]) continue;
                    if (map[newy][newx] > 0) {
                        gmap[newy][newx] = true;
                        gq.push({newy,newx});
                    }

                }
            }
        }
    }
    if (glacier == 0) {cout << 0; return 0;}
}
cout << year;
//////////////////////////////////////////////
return 0;}
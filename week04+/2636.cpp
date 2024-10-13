// https://www.acmicpc.net/problem/2636
// 치즈

// 문제
// 정사각형 칸들로 이루어진 사각형 모양의 판이 있고, 그 위에 얇은 치즈(회색으로 표시된 부분)가 놓여 있다.
// 판의 가장자리에는 치즈가 놓여 있지 않으며 치즈에는 하나 이상의 구멍이 있을 수 있다.
// 이 치즈를 공기 중에 놓으면 녹게 되는데 공기와 접촉된 칸은 한 시간이 지나면 녹아 없어진다.
// 치즈의 구멍 속에는 공기가 없지만 구멍을 둘러싼 치즈가 녹아서 구멍이 열리면 구멍 속으로 공기가 들어가게 된다.
// 치즈의 구멍을 둘러싼 치즈는 녹지 않고 ‘c’로 표시된 부분만 한 시간 후에 녹아 없어진다.
// 입력으로 사각형 모양의 판의 크기와 한 조각의 치즈가 판 위에 주어졌을 때, 공기 중에서 치즈가 모두 녹아 없어지는 데 걸리는 시간과 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에는 사각형 모양 판의 세로와 가로의 길이가 양의 정수로 주어진다. 세로와 가로의 길이는 최대 100이다.
// 판의 각 가로줄의 모양이 윗 줄부터 차례로 둘째 줄부터 마지막 줄까지 주어진다. 치즈가 없는 칸은 0, 치즈가 있는 칸은 1로 주어지며
// 각 숫자 사이에는 빈칸이 하나씩 있다.

// 출력
// 첫째 줄에는 치즈가 모두 녹아서 없어지는 데 걸리는 시간을 출력하고,
// 둘째 줄에는 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 출력한다.

// 예제 입력 1 
// 13 12
// 0 0 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 1 1 0 0 0
// 0 1 1 1 0 0 0 1 1 0 0 0
// 0 1 1 1 1 1 1 0 0 0 0 0
// 0 1 1 1 1 1 0 1 1 0 0 0
// 0 1 1 1 1 0 0 1 1 0 0 0
// 0 0 1 1 0 0 0 1 1 0 0 0
// 0 0 1 1 1 1 1 1 1 0 0 0
// 0 0 1 1 1 1 1 1 1 0 0 0
// 0 0 1 1 1 1 1 1 1 0 0 0
// 0 0 1 1 1 1 1 1 1 0 0 0
// 0 0 0 0 0 0 0 0 0 0 0 0
// 예제 출력 1 
// 3
// 5

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
////////////////////////////////////////////////////////////////
vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
int vertical, horizontal; cin >> vertical >> horizontal;
vector<vector<int>> map(vertical, vector<int>(horizontal, 0));
for (int v = 0; v < vertical; v++) {
    for (int h = 0; h < horizontal; h++) {
        cin >> map[v][h];
    }
}
queue<pair<int,int>> visitq;
vector<int> cheese = {vertical*horizontal};
while(cheese.back()) {
    visitq.push({0,0});
    int count = 0;
    vector<vector<bool>> visitmap(vertical,vector<bool>(horizontal,false));
    visitmap[0][0] = true;
    while(!visitq.empty()) {
        int y = visitq.front().first;
        int x = visitq.front().second;
        visitq.pop();
        for (int d = 0; d < 4; d++) {
            int newy = y + directions[d].first;
            int newx = x + directions[d].second;
            if (newy < 0 || newx < 0 || newy >= vertical || newx >= horizontal || visitmap[newy][newx]) continue;
            if (map[newy][newx] == 0) {
                visitq.push({newy,newx});
                visitmap[newy][newx] = true;
            }
            else if(map[newy][newx] == 1) {
                count++;
                map[newy][newx] = 2;
            }
        }
    }
    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < horizontal; j++) {
            if (map[i][j] == 2) map[i][j] = 0;
        }
    }
    cheese.push_back(count);
}
cout << cheese.size()-2 << "\n" << *(cheese.end()-2);
/////////////////////////////////////////////////////////////////
return 0;}
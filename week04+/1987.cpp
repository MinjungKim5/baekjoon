// https://www.acmicpc.net/problem/1987
// 알파벳

// 문제
// 세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고,
// 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.

// 말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데,
// 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다.
// 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
// 좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오.
// 말이 지나는 칸은 좌측 상단의 칸도 포함된다.

// 입력
// 첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1 ≤ R,C ≤ 20)
// 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 C개의 대문자 알파벳들이 빈칸 없이 주어진다.

// 출력
// 첫째 줄에 말이 지날 수 있는 최대의 칸 수를 출력한다.

// 예제 입력 1 
// 2 4
// CAAB
// ADCB
// 예제 출력 1 
// 3
// 예제 입력 2 
// 3 6
// HFDFFB
// AJHGDH
// DGAGEH
// 예제 출력 2 
// 6

#include <vector>
#include <iostream>
using namespace std;

vector<bool> alphabet(26, false);
vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
vector<string> map;
int maxcount = 0;
int count = 0;
void dfsAndBacktrack(int y, int x) {
    alphabet[map[y][x]-65] = true;
    count++;
    // DFS 재귀
    for (int d = 0; d < 4; d++) {
        int newy = y+directions[d].first;
        int newx = x+directions[d].second;
        if (newy < 0 || newx < 0 || newy >= map.size() || newx >= map[0].size()) continue;
        if (!alphabet[map[newy][newx]-65]) dfsAndBacktrack(newy, newx);
    }
    if (count > maxcount) maxcount = count;
    alphabet[map[y][x]-65] = false;
    count--;
}

int main() {
/////////////////////////////////////////
int vertical, horizontal; cin >> vertical >> horizontal;
for (int v = 0; v < vertical; v++) {
    string str; cin >> str;
    map.push_back(str);
}
dfsAndBacktrack(0,0);
cout << maxcount;
/////////////////////////////////////////
return 0;}
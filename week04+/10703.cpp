// https://www.acmicpc.net/problem/10703
// 유성

// 문제
// 작고 특이한 모양의 유성 사진이 인터넷에 올라왔다. 사진에는 매우 높은 곳에서 떨어지고 있는 유성이 허공에 찍혀 있었다.
// 유성이 떨어지고 난 뒤의 사진도 있었지만 안타깝게도 소실돼버려 이를 복원해야 한다.
// 유성 사진을 문자의 배열로 단순화시켜 표기할 것이다.
// 문자 'X'는 유성의 일부를, 문자 '#'는 땅의 일부를, 그리고 나머지(공기)는 문자 '.'로 이루어져 있다.
// 모든 유성 조각들은 연결되어 있다.
// 즉, 두 부분 유성이 존재한다면, 한 쪽에서 유성 조각을 통해 상하좌우로 이동해서 다른 부분 유성에 도달할 수 있다.
// 땅 또한 같은 방식으로 연결되어 있다.
// 주어진 사진에서 유성은 땅보다 위에 있다.
// 정확히 말하자면, 적어도 한 줄 이상의 공기('.')가 존재하며, 유성은 그 보다 위에, 땅은 그 보다 아래쪽에 있다.
// 또한, 사진의 맨 밑 줄은 모두 땅이다.
// 유성은 수직으로 낙하한다. 유성이 땅에 떨어졌을 때, 유성과 땅은 원형을 유지한다고 한다. 유성이 떨어진 후의 사진을 복구하여라.

// 입력
// 첫 번째 줄에는 각각 사진의 세로와 가로 길이를 의미하는 정수 R과 S (3 ≤ R, S ≤ 3 000)가 주어진다.
// 다음 R 개의 줄에는 문자로 단순화된 사진이 주어진다.

// 출력
// 유성이 떨어지고 난 뒤의 사진(크기 R × S)을 복원하여 출력하라.

// 예제 입력 1 
// 5 6
// .XXXX.
// ...X..
// ......
// #..###
// ######
// 예제 출력 1 
// ......
// .XXXX.
// ...X..
// #..###
// ######
// 예제 입력 2 
// 9 7
// XXX.XXX
// X.XXX.X
// X..X..X
// X.....X
// .......
// .#...#.
// .##.##.
// .#####.
// #######
// 예제 출력 2 
// .......
// .......
// .......
// .......
// XXX.XXX
// X#XXX#X
// X##X##X
// X#####X
// #######

#include <vector>
#include <iostream>
using namespace std;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
///////////////////////////////////////
int vertical, horizontal; cin >> vertical >> horizontal;
vector<vector<char>> map(vertical, vector<char> (horizontal));
vector<vector<char>> newmap(vertical, vector<char> (horizontal));
vector<int> meteor(horizontal,-9999);
vector<int> land(horizontal,9999);
for (int v = 0; v < vertical; v++) {
    for (int h = 0; h < horizontal; h++) {
        char chr; cin >> chr;
        map[v][h] = chr;
        if (chr != 'X') newmap[v][h] = chr;
        if (chr == 'X') {meteor[h] = v; newmap[v][h] = '.';}
        if (chr == '#' && land[h] > v) land[h] = v;
    }
}
int altitude = 0;
int minval = 9999;
for (int h = 0; h < horizontal; h++) {
    if (altitude < meteor[h]) altitude = meteor[h];
    if (minval > land[h]-meteor[h]) minval = land[h]-meteor[h];
}
for (int v = 0; v <= altitude; v++) {
    for (int h = 0; h < horizontal; h++) {
        if (map[v][h] == 'X') newmap[v+minval-1][h] = 'X';
    }
}
for (int v = 0; v < vertical; v++) {
    for (int h = 0; h < horizontal; h++) {
        cout << newmap[v][h];
    }
    cout << "\n";
}
///////////////////////////////////////
return 0;}
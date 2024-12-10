// https://www.acmicpc.net/problem/1743
// 음식물 피하기

// 문제
// 코레스코 콘도미니엄 8층은 학생들이 3끼의 식사를 해결하는 공간이다.
// 그러나 몇몇 비양심적인 학생들의 만행으로 음식물이 통로 중간 중간에 떨어져 있다.
// 이러한 음식물들은 근처에 있는 것끼리 뭉치게 돼서 큰 음식물 쓰레기가 된다. 
// 이 문제를 출제한 선생님은 개인적으로 이러한 음식물을 실내화에 묻히는 것을 정말 진정으로 싫어한다.
// 통로에 떨어진 음식물을 피해가기란 쉬운 일이 아니다. 따라서 선생님은 떨어진 음식물 중에 제일 큰 음식물만은 피해 가려고 한다. 

// 입력
// 첫째 줄에 통로의 세로 길이 N(1 ≤ N ≤ 100)과 가로 길이 M(1 ≤ M ≤ 100) 그리고 음식물 쓰레기의 개수 K(1 ≤ K ≤ N×M)이 주어진다. 
// 그리고 다음 K개의 줄에 음식물이 떨어진 좌표 (r, c)가 주어진다.

// 좌표 (r, c)의 r은 위에서부터, c는 왼쪽에서부터가 기준이다. 입력으로 주어지는 좌표는 중복되지 않는다.

// 출력
// 첫째 줄에 음식물 중 가장 큰 음식물의 크기를 출력하라.

// 예제 입력 1 
// 3 4 5
// 3 2
// 2 2
// 3 1
// 2 3
// 1 1
// 예제 출력 1 
// 4

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
///////////////////////////////////////
vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
vector<int> wastes;
unordered_map<int,int> map;
int vertical, horizontal, k; cin >> vertical >> horizontal >> k;
for (int i = 0; i < k; i++) {
    int y, x; cin >> y >> x;
    int hashedCord = 1000*y+x;
    wastes.push_back(hashedCord);
    map[hashedCord] = 1;
}
int maxval = 0;
for (int waste: wastes) {
    if (map[waste] != 1)continue;
    map[waste] = 0;
    int count = 1;
    queue<int> q;
    q.push(waste);
    while(!q.empty()) {
        int y = q.front()/1000;
        int x = q.front()%1000;
        q.pop();
        for (pair<int,int> d: dir) {
            int newy = y+d.first;
            int newx = x+d.second;
            int newcord = newy*1000+newx;
            if (map[newcord] == 1) {
                map[newcord] = 0;
                q.push(newcord);
                count++;
                if (maxval < count) maxval = count;
            }
        }
    }
}
cout << maxval;
///////////////////////////////////////
return 0;}
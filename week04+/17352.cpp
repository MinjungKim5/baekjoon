// https://www.acmicpc.net/problem/17352
// 여러분의 다리가 되어 드리겠습니다!

// 문제
// 선린월드에는 N개의 섬이 있다. 섬에는 1, 2, ..., N의 번호가 하나씩 붙어 있다. 그 섬들을 N - 1개의 다리가 잇고 있으며, 어떤 두 섬 사이든 다리로 왕복할 수 있다.
// 어제까지는 그랬다.
// "왜 다리가 N - 1개밖에 없냐, 통행하기 불편하다"며 선린월드에 불만을 갖던 욱제가 다리 하나를 무너뜨렸다!
// 안 그래도 불편한 통행이 더 불편해졌다. 서로 왕복할 수 없는 섬들이 생겼기 때문이다.
// 일단 급한 대로 정부는 선린월드의 건축가를 고용해, 서로 다른 두 섬을 다리로 이어서 다시 어떤 두 섬 사이든 왕복할 수 있게 하라는 지시를 내렸다.
// 그런데 그 건축가가 당신이다! 안 그래도 천하제일 코딩대회에 참가하느라 바쁜데...

// 입력
// 첫 줄에 정수 N이 주어진다. (2 ≤ N ≤ 300,000)
// 그 다음 N - 2개의 줄에는 욱제가 무너뜨리지 않은 다리들이 잇는 두 섬의 번호가 주어진다.

// 출력
// 다리로 이을 두 섬의 번호를 출력한다. 여러 가지 방법이 있을 경우 그 중 아무거나 한 방법만 출력한다.

// 예제 입력 1 
// 4
// 1 2
// 1 3
// 예제 출력 1 
// 1 4

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
ios_base :: sync_with_stdio(false); 
cin.tie(NULL); 
cout.tie(NULL);
//////////////////////////////////////////////
int n_of_island; cin >> n_of_island;

vector<vector<int>> adjlist(n_of_island+1);
vector<bool> visited(n_of_island+1, false);
visited[0] = true; visited[1] = true;
queue<int> will_visit;
for (int n = 1; n < n_of_island-1; n++) {
    int a, b; cin >> a >> b;
    if (a == 1) {
        will_visit.push(b);
        visited[b] = true;
        }
    else if (b == 1) {
        will_visit.push(a);
        visited[a] = true;
    }
    else {
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
}

while (!will_visit.empty()) {
    int island = will_visit.front();
    will_visit.pop();
    for (int i = 0; i < adjlist[island].size(); i++) {
        int adj = adjlist[island][i];
        if (visited[adj]) continue;
        else {will_visit.push(adj); visited[adj] = true;}
    }
}

for (int n = 2; n < n_of_island +1; n++) {
    if (!visited[n]) {cout << 1 << " " << n; return 0;}
}
//////////////////////////////////////////////
return 0;}
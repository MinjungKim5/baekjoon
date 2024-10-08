// https://www.acmicpc.net/problem/11779
// 최소비용 구하기 2

// 문제
// n(1≤n≤1,000)개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1≤m≤100,000)개의 버스가 있다.
// 우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. 그러면 A번째 도시에서 B번째 도시 까지 가는데 드는 최소비용과 경로를 출력하여라.
// 항상 시작점에서 도착점으로의 경로가 존재한다.

// 입력
// 첫째 줄에 도시의 개수 n(1≤n≤1,000)이 주어지고 둘째 줄에는 버스의 개수 m(1≤m≤100,000)이 주어진다.
// 그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다.
// 그리고 그 다음에는 도착지의 도시 번호가 주어지고 또 그 버스 비용이 주어진다. 버스 비용은 0보다 크거나 같고, 100,000보다 작은 정수이다.
// 그리고 m+3째 줄에는 우리가 구하고자 하는 구간 출발점의 도시번호와 도착점의 도시번호가 주어진다.

// 출력
// 첫째 줄에 출발 도시에서 도착 도시까지 가는데 드는 최소 비용을 출력한다.
// 둘째 줄에는 그러한 최소 비용을 갖는 경로에 포함되어있는 도시의 개수를 출력한다. 출발 도시와 도착 도시도 포함한다.
// 셋째 줄에는 최소 비용을 갖는 경로를 방문하는 도시 순서대로 출력한다. 경로가 여러가지인 경우 아무거나 하나 출력한다.

// 예제 입력 1 
// 5
// 8
// 1 2 2
// 1 3 3
// 1 4 1
// 1 5 10
// 2 4 2
// 3 4 1
// 3 5 1
// 4 5 3
// 1 5
// 예제 출력 1 
// 4
// 3
// 1 3 5

#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#define INF 2000000000
using namespace std;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//////////////////////////////////////////////
int nOfCities, mOfBuses; cin >> nOfCities >> mOfBuses;
vector<vector<vector<int>>> adjlist(nOfCities+1);
vector<pair<int,int>> costlist(nOfCities+1, {0,INF});
vector<bool> visited(nOfCities+1);
for (int m = 0; m < mOfBuses; m++) {
    int frm, to, cost; cin >> frm >> to >> cost;
    adjlist[frm].push_back({cost, frm, to});
}
int from, to; cin >> from >> to;
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> visitq;
for (vector<int> ele: adjlist[from]) visitq.push(ele);
costlist[from].second = 0;
visited[from] = true;
// dijkstra
while (!visitq.empty()) {
    vector<int> adj = visitq.top(); visitq.pop();
    visited[adj[2]] = true;
    if (visited[adj[1]] && costlist[adj[2]].second > costlist[adj[1]].second + adj[0]) {
        costlist[adj[2]] = {adj[1], costlist[adj[1]].second + adj[0]};
        for (vector<int> e: adjlist[adj[2]]) visitq.push(e);
    }
}
cout << costlist[to].second << endl;

// 경유지 확인
stack<int> origins;
int origin = to;
while (origin != 0) {
    origins.push(origin);
    origin = costlist[origin].first;
}
cout << origins.size() << endl;
while (!origins.empty()) {cout << origins.top() << " "; origins.pop();}
//////////////////////////////////////////////
return 0;}
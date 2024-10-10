// https://www.acmicpc.net/problem/15681
// 트리와 쿼리

// 문제
// 간선에 가중치와 방향성이 없는 임의의 루트 있는 트리가 주어졌을 때, 아래의 쿼리에 답해보도록 하자.
// 정점 U를 루트로 하는 서브트리에 속한 정점의 수를 출력한다.
// 만약 이 문제를 해결하는 데에 어려움이 있다면, 하단의 힌트에 첨부한 문서를 참고하자.

// 입력
// 트리의 정점의 수 N과 루트의 번호 R, 쿼리의 수 Q가 주어진다. (2 ≤ N ≤ 105, 1 ≤ R ≤ N, 1 ≤ Q ≤ 105)
// 이어 N-1줄에 걸쳐, U V의 형태로 트리에 속한 간선의 정보가 주어진다. (1 ≤ U, V ≤ N, U ≠ V)
// 이는 U와 V를 양 끝점으로 하는 간선이 트리에 속함을 의미한다.
// 이어 Q줄에 걸쳐, 문제에 설명한 U가 하나씩 주어진다. (1 ≤ U ≤ N)
// 입력으로 주어지는 트리는 항상 올바른 트리임이 보장된다.

// 출력
// Q줄에 걸쳐 각 쿼리의 답을 정수 하나로 출력한다.

// 예제 입력 1 
// 9 5 3
// 1 3
// 4 3
// 5 4
// 5 6
// 6 7
// 2 3
// 9 6
// 6 8
// 5
// 4
// 8
// 예제 출력 1 
// 9
// 4
// 1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs (int parent, int curr, vector<vector<int>> *adjlist, vector<int> *counts, vector<int> *visited) {
    for (int i = 0; i < (*adjlist)[curr].size(); i++) {
        if ((*visited)[(*adjlist)[curr][i]]) continue;
        (*visited)[(*adjlist)[curr][i]] = true;
        dfs(curr, (*adjlist)[curr][i], adjlist, counts, visited);
    }
    (*counts)[parent] += (*counts)[curr]+1;
}

int main () {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
////////////////////////////////////////////
int nOfVertex, root, qOfQueries; cin >> nOfVertex >> root >> qOfQueries;
vector<vector<int>> adjlist(nOfVertex+1);
vector<int> counts(nOfVertex+1,0);
vector<int> visited(nOfVertex+1, false);
for (int n = 1; n < nOfVertex; n++) {
    int a, b; cin >> a >> b;
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
}
visited[root] = true;
dfs(0,root,&adjlist,&counts,&visited);
for (int q = 0; q < qOfQueries; q++) {
    int qroot; cin >> qroot;
    cout << counts[qroot]+1 << "\n";
}
////////////////////////////////////////////
return 0;}
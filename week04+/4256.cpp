// https://www.acmicpc.net/problem/4256
// 트리

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


stack<int> post;

void travel(vector<int> *pre, vector<int> *mid, vector<bool> *checked, int rootPre, int rootMid, int nodes) {
    int rootNum = (*pre)[rootPre];
    (*checked)[rootNum] = true;
    post.push(rootNum);
    // 오른쪽 서브루트 찾기
    for (int i = rootPre+1; i < nodes; i++) {
        if ((*checked)[(*pre)[i]]) continue;
        for (int j = rootMid+1; j < nodes; j++) {
            if ((*pre)[i] == (*mid)[j]) {
                travel(pre, mid, checked, i, j, nodes);
                break;
            }
        }
    }

    // 왼쪽 서브루트 찾기
    if (rootPre+1<nodes && !(*checked)[(*pre)[rootPre+1]]) {
        for (int j = 0; j < rootMid; j++) {
            if ((*pre)[rootPre+1] == (*mid)[j]) {
                travel(pre, mid, checked, rootPre+1, j, nodes);
                break;
            }
        }
    }
}

int main() {
////////////////////////////////////////
int testcase; cin >> testcase;
for (int t = 0; t < testcase; t++) {
    int nodes; cin >> nodes;
    vector<int> pre(nodes);
    vector<int> mid(nodes);
    for (int n = 0; n < nodes; n++) cin >> pre[n];
    for (int n = 0; n < nodes; n++) cin >> mid[n];
    vector<bool> checked(nodes+1, false); checked[0] = true;
    int rootMid;
    for (int j = 0; j < nodes; j++) {
        if (pre[0] == mid[j]) rootMid = j;
    }
    travel(&pre, &mid, &checked, 0, rootMid, nodes);
    while (!post.empty()) {
        cout << post.top() << " ";
        post.pop();
    }
    cout << "\n";
}
////////////////////////////////////////
return 0;}
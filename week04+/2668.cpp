// https://www.acmicpc.net/problem/2668
// 숫자 고르기

// 문제
// 세로 두 줄, 가로로 N개의 칸으로 이루어진 표가 있다.
// 첫째 줄의 각 칸에는 정수 1, 2, …, N이 차례대로 들어 있고 둘째 줄의 각 칸에는 1이상 N이하인 정수가 들어 있다.
// 첫째 줄에서 숫자를 적절히 뽑으면, 그 뽑힌 정수들이 이루는 집합과, 뽑힌 정수들의 바로 밑의 둘째 줄에 들어있는 정수들이 이루는 집합이 일치한다.
// 이러한 조건을 만족시키도록 정수들을 뽑되, 최대로 많이 뽑는 방법을 찾는 프로그램을 작성하시오. 예를 들어, N=7인 경우 아래와 같이 표가 주어졌다고 하자.
// 이 경우에는 첫째 줄에서 1, 3, 5를 뽑는 것이 답이다. 첫째 줄의 1, 3, 5밑에는 각각 3, 1, 5가 있으며 두 집합은 일치한다. 이때 집합의 크기는 3이다.
// 만약 첫째 줄에서 1과 3을 뽑으면, 이들 바로 밑에는 정수 3과 1이 있으므로 두 집합이 일치한다.
// 그러나, 이 경우에 뽑힌 정수의 개수는 최대가 아니므로 답이 될 수 없다.

// 입력
// 첫째 줄에는 N(1≤N≤100)을 나타내는 정수 하나가 주어진다. 그 다음 줄부터는 표의 둘째 줄에 들어가는 정수들이 순서대로 한 줄에 하나씩 입력된다.

// 출력
// 첫째 줄에 뽑힌 정수들의 개수를 출력하고, 그 다음 줄부터는 뽑힌 정수들을 작은 수부터 큰 수의 순서로 한 줄에 하나씩 출력한다.

// 예제 입력 1 
// 7
// 3
// 1
// 1
// 5
// 5
// 4
// 6
// 예제 출력 1 
// 3
// 1
// 3
// 5

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main() {
/////////////////////////////////////////
int nOfNums; cin >> nOfNums;
vector<int> nums(nOfNums+1,0);
for (int n = 1; n <= nOfNums; n++) {
    cin >> nums[n];
}
vector<bool> isin(nOfNums+1,false);
for (int n = 1; n <=nOfNums; n++) {
    vector<bool> visited(nOfNums+1, false);
    stack<int> visitstk;
    visitstk.push(n);
    visited[n] = true;
    while (!visitstk.empty()) {
        int curr = visitstk.top(); visitstk.pop();
        if (0 < nums[curr] && nums[curr] <= nOfNums && !isin[nums[curr]]) {
            if (nums[curr] == n) {
                for (int i = 1; i <= nOfNums; i++) {
                    if (visited[i]) isin[i] = true;
                }
                break;
            }
            if (!visited[nums[curr]]) {
                visitstk.push(nums[curr]);
                visited[nums[curr]] = true;
            }
        }
    }
}
queue<int> resq;
for (int n = 1; n <= nOfNums; n++) {
    if (isin[n]) resq.push(n);
}
cout << resq.size() << "\n";
while (!resq.empty()) {
    cout << resq.front() << "\n";
    resq.pop();
}
/////////////////////////////////////////
return 0;}
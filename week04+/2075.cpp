// https://www.acmicpc.net/problem/2075
// N번째 큰 수

// 문제
// N×N의 표에 수 N2개 채워져 있다. 채워진 수에는 한 가지 특징이 있는데, 모든 수는 자신의 한 칸 위에 있는 수보다 크다는 것이다. N=5일 때의 예를 보자.
// 12	7	9	15	5
// 13	8	11	19	6
// 21	10	26	31	16
// 48	14	28	35	25
// 52	20	32	41	49
// 이러한 표가 주어졌을 때, N번째 큰 수를 찾는 프로그램을 작성하시오. 표에 채워진 수는 모두 다르다.

// 입력
// 첫째 줄에 N(1 ≤ N ≤ 1,500)이 주어진다. 다음 N개의 줄에는 각 줄마다 N개의 수가 주어진다.
// 표에 적힌 수는 -10억보다 크거나 같고, 10억보다 작거나 같은 정수이다.

// 출력
// 첫째 줄에 N번째 큰 수를 출력한다.

// 예제 입력 1 
// 5
// 12 7 9 15 5
// 13 8 11 19 6
// 21 10 26 31 16
// 48 14 28 35 25
// 52 20 32 41 49
// 예제 출력 1 
// 35

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<stack<int>> stacks;
priority_queue<pair<int,int>> heapq;
int bigNum() {
    int idx = heapq.top().second;
    int big = heapq.top().first;
    stacks[idx].pop();
    heapq.pop();
    heapq.push({stacks[idx].top(), idx});
    return big;
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//////////////////////////////////////////
int size; cin >> size;
for (int s = 0; s < size; s++) stacks.push_back(stack<int>({-2000000001}));
for (int s = 0; s < size; s++) {
    for (int i = 0; i < size; i++) {
        int num; cin >> num;
        stacks[i].push(num);
        if (s == size-1) heapq.push({num,i});
    }
}
for (int n = 1; n < size; n++) bigNum();
cout << bigNum();
//////////////////////////////////////////
return 0;}
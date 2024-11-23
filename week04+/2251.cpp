// https://www.acmicpc.net/problem/2251
// 물통

// 문제
// 각각 부피가 A, B, C(1≤A, B, C≤200) 리터인 세 개의 물통이 있다. 처음에는 앞의 두 물통은 비어 있고, 세 번째 물통은 가득(C 리터) 차 있다.
// 이제 어떤 물통에 들어있는 물을 다른 물통으로 쏟아 부을 수 있는데, 이때에는 한 물통이 비거나, 다른 한 물통이 가득 찰 때까지 물을 부을 수 있다. 이 과정에서 손실되는 물은 없다고 가정한다.
// 이와 같은 과정을 거치다보면 세 번째 물통(용량이 C인)에 담겨있는 물의 양이 변할 수도 있다
//  첫 번째 물통(용량이 A인)이 비어 있을 때, 세 번째 물통(용량이 C인)에 담겨있을 수 있는 물의 양을 모두 구해내는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 세 정수 A, B, C가 주어진다.

// 출력
// 첫째 줄에 공백으로 구분하여 답을 출력한다. 각 용량은 오름차순으로 정렬한다.

// 예제 입력 1 
// 8 9 10
// 예제 출력 1 
// 1 2 8 9 10

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

struct bottles
{
    int a;
    int b;
    int c;
};
pair<int,int> pour(pair<int,int> fromTo, int limit) {
    int from = fromTo.first;
    int to = fromTo.second;
    to += from;
    from = 0;
    if (to > limit) {
        from = to-limit;
        to = limit;
    }
    return {from,to};
}

int hashBottles(bottles bottles) {
    return bottles.a*201*201+bottles.b*201+bottles.c;
}

int main() {
/////////////////////////////////////
unordered_map<int,bool> visited;
bottles limit;
cin >> limit.a >> limit.b >> limit.c;
queue<bottles> q;
q.push({0,0,limit.c});
visited[limit.c] = true;
vector<int> possible = {limit.c};
while (!q.empty()) {
    int a = q.front().a;
    int b = q.front().b;
    int c = q.front().c;
    q.pop();
    // a->b
    pair<int,int>pourRes = pour({a,b},limit.b);
    bottles bottleRes = {pourRes.first,pourRes.second,c};
    if (!visited.count(hashBottles(bottleRes))) {
        visited[hashBottles(bottleRes)] = true;
        q.push(bottleRes);
        if (bottleRes.a == 0) possible.push_back(bottleRes.c);
    }
    // a->c
    pourRes = pour({a,c},limit.c);
    bottleRes = {pourRes.first,b,pourRes.second};
    if (!visited.count(hashBottles(bottleRes))) {
        visited[hashBottles(bottleRes)] = true;
        q.push(bottleRes);
        if (bottleRes.a == 0) possible.push_back(bottleRes.c);
    }
    // b->c
    pourRes = pour({b,c},limit.c);
    bottleRes = {a,pourRes.first,pourRes.second};
    if (!visited.count(hashBottles(bottleRes))) {
        visited[hashBottles(bottleRes)] = true;
        q.push(bottleRes);
        if (bottleRes.a == 0) possible.push_back(bottleRes.c);
    }
    // b->a
    pourRes = pour({b,a},limit.a);
    bottleRes = {pourRes.second,pourRes.first,c};
    if (!visited.count(hashBottles(bottleRes))) {
        visited[hashBottles(bottleRes)] = true;
        q.push(bottleRes);
        if (bottleRes.a == 0) possible.push_back(bottleRes.c);
    }
    // c->a
    pourRes = pour({c,a},limit.a);
    bottleRes = {pourRes.second,b,pourRes.first};
    if (!visited.count(hashBottles(bottleRes))) {
        visited[hashBottles(bottleRes)] = true;
        q.push(bottleRes);
        if (bottleRes.a == 0) possible.push_back(bottleRes.c);
    }
    // c->b
    pourRes = pour({c,b},limit.b);
    bottleRes = {a,pourRes.second,pourRes.first};
    if (!visited.count(hashBottles(bottleRes))) {
        visited[hashBottles(bottleRes)] = true;
        q.push(bottleRes);
        if (bottleRes.a == 0) possible.push_back(bottleRes.c);
    }
}
sort(possible.begin(), possible.end());
for (int p: possible) cout << p << " ";
/////////////////////////////////////
return 0;}
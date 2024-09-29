// https://www.acmicpc.net/problem/22251
// 빌런 호석

#include <iostream>
#include <vector>
using namespace std;

int main() {
//////////////////////////////////////
int n,k,p,x; cin >> n >> k >> p >> x;
vector<vector<int>> convertTable;
int count = 0;
convertTable.push_back({0,4,3,3,4,3,2,3,1,2});
convertTable.push_back({4,0,5,3,2,5,6,1,5,4});
convertTable.push_back({3,5,0,2,5,4,3,4,2,3});
convertTable.push_back({3,3,2,0,3,2,3,2,2,1});
convertTable.push_back({4,2,5,3,0,3,4,3,3,2});
convertTable.push_back({3,5,4,2,3,0,1,4,2,1});
convertTable.push_back({2,6,3,3,4,1,0,5,1,2});
convertTable.push_back({3,1,4,2,3,4,5,0,4,3});
convertTable.push_back({1,5,2,2,3,2,1,4,0,1});
convertTable.push_back({2,4,3,1,2,1,2,3,1,0});
for (int i = 1; i <= n; i++) {
    int cost = 0;
    int y = x;
    int z = i;
    for (int d = 0; d < k; d++) {
        int from = y%10;
        int to = z%10;
        cost += convertTable[from][to];
        y=y/10;
        z=z/10;
    }
    if (0 < cost && cost <= p) {
        count++;
        // cout << i << " ";
    }
}
cout << count;
//////////////////////////////////////
return 0;}
// https://www.acmicpc.net/problem/1315
// RPG

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<vector<bool>> visited(1000, vector<bool>(1000,false));
vector<vector<int>> quests;
vector<vector<int>> :: iterator iter;
queue<pair<int,int>> q;
int maxq = 0;
int n_of_quest;

void check_my_quest(int str, int itl) {
    int stat_before = str+itl;
    int stat_after = 0;
    int count = 0;
    for (iter = quests.begin(); iter != quests.end(); iter++) {
        if (str >= (*iter)[0] || itl >= (*iter)[1]) {stat_after += (*iter)[2]; count+=1;}
    }
    if (count > maxq) maxq = count;
    int bonus = stat_after-stat_before;
    for (int i = 0; i <= bonus; i++) {
        int newstr = str + i;
        int newitl = itl + bonus-i;
        if (newstr < 1000 && newitl < 1000 && !visited[newstr][newitl]) {
            visited[newstr][newitl] = true;
            q.push({newstr,newitl});
        }
        if (newstr >= 999 && newitl >= 999) {maxq = n_of_quest; return;}
    }
}

int main() {
/////////////////////////////////////////////
cin >> n_of_quest;
for (int n = 0; n < n_of_quest; n++) {
    int s, i, b; cin >> s >> i >> b;
    quests.push_back({s-1, i-1, b});
}
visited[0][0] = true;
q.push({0,0});
while(!q.empty()) {
    pair<int,int> stats = q.front();
    q.pop();
    check_my_quest(stats.first,stats.second);
    if (maxq == n_of_quest) {cout<< n_of_quest; return 0;}
}
cout << maxq;
/////////////////////////////////////////////
return 0;}
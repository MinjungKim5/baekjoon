// https://www.acmicpc.net/problem/27172
// 수 나누기 게임

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> scores(1000001,0);
vector<vector<int>> winners(1000001, {1});
vector<bool> isin(1000001,false);
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
/////////////////////////////////////////
int nOfPlayers; cin >> nOfPlayers;
vector<int> player(nOfPlayers,0);
vector<int> nums(nOfPlayers,0);

for (int p = 0; p < nOfPlayers; p++) {
    int num; cin >> num;
    player[p] = num;
    isin[num] = true;
    for (int i = 2; i*i <= num; i++) {
        if (num%i==0) {
            winners[num].push_back(i);
            if (i*i == num) continue;
            winners[num].push_back(num/i);
        }
    }
}

for (int p = 0; p < nOfPlayers; p++) {
    for (int winner: winners[player[p]]) {
        if (isin[winner]) {
            scores[player[p]]--;
            scores[winner]++;
        }
    }
}

for (int p = 0; p < nOfPlayers; p++) {
    int curr = player[p];
    cout << scores[curr] << " ";
} 
/////////////////////////////////////////
return 0;}
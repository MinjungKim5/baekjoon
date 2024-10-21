// https://www.acmicpc.net/problem/27172
// 수 나누기 게임

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
/////////////////////////////////////////
int nOfPlayers; cin >> nOfPlayers;
vector<int> player(nOfPlayers,0);
vector<bool> isin(1000001,false);
int maxval = 0;
for (int p = 0; p < nOfPlayers; p++) {
    int num; cin >> num;
    if (maxval < num) maxval = num;
    player[p] = num;
    isin[num] = true;
}
vector<int> scores(maxval+1,0);
for (int p = 0; p < nOfPlayers; p++) {
    int num = player[p];
    for (int loser = 2*num; loser <= maxval; loser+=num) {
        if (isin[loser]) {
            scores[loser]--;
            scores[num]++;
        }
    }
}

for (int p = 0; p < nOfPlayers; p++) {
    int curr = player[p];
    cout << scores[curr] << " ";
} 
/////////////////////////////////////////
return 0;}
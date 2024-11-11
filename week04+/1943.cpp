// https://www.acmicpc.net/problem/1943
// 동전 분배

// 문제
// 윤화와 준희는 솔선수범하여 쓰레기를 줍는 착한 일을 하였다.
// 원장선생님께서는 윤화와 준희를 칭찬하시고 과자나 사 먹으라고 하시며 동전 몇 개를 윤화와 준희에게 건네 주었다.
// 그런데 돈을 받은 윤화와 준희는 좋아하기보다 고민에 빠지고 말았다. 원장선생님께 받은 이 돈을 어떻게 나누어 할지 고민에 빠진 것이다.
// 두 사람 모두 상대방이 자기보다 1원이라도 더 받는 것은 도저히 인정할 수 없어 한다.
// 따라서 돈을 똑같이 둘로 나누어 가져야 두 사람이 모두 만족할 수 있게 된다.
// 하지만 두 사람에게 돈을 똑같이 나누는 것이 불가능한 경우도 있다.
// 예를 들어 500원짜리 1개와 50원짜리 1개를 받았다면, 이 돈을 두 사람이 똑같이 나누어 가질 수는 없다.
// 물론 동전을 반으로 잘라서 나누어 가질 수도 있겠지만 그러면 돈으로서의 가치를 잃기 때문에 그렇게 할 수는 없다.
// 원장 선생님께서 N가지 종류의 동전을 각각 몇 개씩 주셨을 때, 그 돈을 반으로 나눌 수 있는지 없는지 판단하자.

// 입력
// 세 개의 입력이 주어진다. 각 입력의 첫째 줄에 동전의 종류 N(1 ≤ N ≤ 100)이 주어진다.
// 각 입력의 둘째 줄부터 N+1째 줄까지 각각의 동전의 금액과 개수가 빈 칸을 사이에 두고 주어진다.
// 단, 원장선생님께서 주신 금액의 총 합은 100,000원을 넘지 않는다. 동전의 금액과 개수는 자연수이고, 같은 금액을 가진 동전이 두 번 이상 주어지는 경우는 없다.

// 출력
// 첫째 줄부터 세 줄에 걸쳐, 각 입력에 대하여 반으로 나누는 것이 가능하면 1, 불가능하면 0을 출력한다.

// 예제 입력 1 
// 2
// 500 1
// 50 1
// 3
// 100 2
// 50 1
// 10 5
// 3
// 1 1
// 2 1
// 3 1
// 예제 출력 1 
// 0
// 1
// 1

#include <iostream>
#include <vector>
using namespace std;

int divide() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nOfCoins; cin >> nOfCoins;
    int total = 0;
    vector<pair<int,int>> coins(nOfCoins+1);
    for (int n = 0; n < nOfCoins; n++) {
        int coin, count; cin >> coin >> count;
        coins[n+1] = {coin,count};
        total += coin*count;
    }
    if (total%2) return 0;
    int goal = total/2;
    vector<vector<int>> dptable(nOfCoins+1,vector<int>(goal+1,-1));
    for (int v = 0; v <= nOfCoins; v++) dptable[v][0] = 0;
    for (int i = 1; i <= nOfCoins; i++) {
        int coin = coins[i].first;
        int count = coins[i].second;
        for (int j = 1; j <= goal; j++) {
            if (dptable[i-1][j] >= 0) dptable[i][j] = 0;
            else if (j-coin >= 0 && dptable[i-1][j-coin] >=0) dptable[i][j] = 1;
            else if (j-coin >= 0 && 0 <= dptable[i][j-coin] && dptable[i][j-coin] < count) dptable[i][j] = dptable[i][j-coin]+1;

            if (j == goal && dptable[i][j] >= 0) return 1;
        }
    }
    return 0;
}

int main() {
    for (int t = 0; t < 3; t++) {
        cout << divide() << endl;
    }
    return 0;
}
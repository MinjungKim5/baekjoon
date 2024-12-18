// https://www.acmicpc.net/problem/2169
// 로봇 조종하기

// 문제
// NASA에서는 화성 탐사를 위해 화성에 무선 조종 로봇을 보냈다.
// 실제 화성의 모습은 굉장히 복잡하지만, 로봇의 메모리가 얼마 안 되기 때문에 지형을 N×M 배열로 단순화 하여 생각하기로 한다.
// 지형의 고저차의 특성상, 로봇은 움직일 때 배열에서 왼쪽, 오른쪽, 아래쪽으로 이동할 수 있지만, 위쪽으로는 이동할 수 없다.
// 또한 한 번 탐사한 지역(배열에서 하나의 칸)은 탐사하지 않기로 한다.
// 각각의 지역은 탐사 가치가 있는데, 로봇을 배열의 왼쪽 위 (1, 1)에서 출발시켜 오른쪽 아래 (N, M)으로 보내려고 한다.
// 이때, 위의 조건을 만족하면서, 탐사한 지역들의 가치의 합이 최대가 되도록 하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N, M(1≤N, M≤1,000)이 주어진다. 다음 N개의 줄에는 M개의 수로 배열이 주어진다. 배열의 각 수는 절댓값이 100을 넘지 않는 정수이다.
// 이 값은 그 지역의 가치를 나타낸다.

// 출력
// 첫째 줄에 최대 가치의 합을 출력한다.

// 예제 입력 1 
// 5 5
// 10 25 7 8 13
// 68 24 -78 63 32
// 12 -69 100 -29 -25
// -16 -22 -57 -33 99
// 7 -76 -11 77 15
// 예제 출력 1 
// 319

#include <iostream>
#include <vector>
using namespace std;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
/////////////////////////////////////////
int vertical, horizontal; cin >> vertical >> horizontal;
vector<vector<int>> map(vertical, vector<int>(horizontal,0));
vector<vector<int>> sumMap(vertical, vector<int>(horizontal,0));
vector<vector<int>> sumRightMap(vertical, vector<int>(horizontal,0));
vector<vector<int>> sumLeftMap(vertical, vector<int>(horizontal,0));
for (int v = 0; v < vertical; v++) {
    for (int h = 0; h < horizontal; h++) {
        cin >> map[v][h];
    }
}
sumMap[0][0] = map[0][0];
for (int h = 1; h < horizontal; h++) {
    sumMap[0][h] = sumMap[0][h-1] + map[0][h];
}
for (int v = 1; v < vertical; v++) {
    sumRightMap[v][0] = sumMap[v-1][0]+map[v][0];
    for (int h = 1; h < horizontal; h++) {
        sumRightMap[v][h] = max<int>(sumMap[v-1][h], sumRightMap[v][h-1])+map[v][h];
    }

    sumLeftMap[v][horizontal-1] = sumMap[v-1][horizontal-1]+map[v][horizontal-1];
    for (int h = horizontal-2; h >= 0; h--) {
        sumLeftMap[v][h] = max<int>(sumMap[v-1][h], sumLeftMap[v][h+1])+map[v][h];
    }

    for (int h = 0; h< horizontal; h++) {
        sumMap[v][h] = max<int>(sumLeftMap[v][h], sumRightMap[v][h]);
    }
}
cout << sumMap[vertical-1][horizontal-1];
/////////////////////////////////////////
return 0;}
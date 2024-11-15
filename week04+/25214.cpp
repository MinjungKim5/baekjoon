// 크림 파스타

// 예제 입력 1 
// 6
// 50 100 70 110 10 100
// 예제 출력 1 
// 0 50 50 60 60 90
// 예제 입력 2 
// 6
// 3 3 2 8 3 1000000000
// 예제 출력 2 
// 0 0 0 6 6 999999998

#include <iostream>
#include <vector>
using namespace std;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
////////////////////////////////////////////
int nOfNums; cin >> nOfNums;
vector<int> dptable(nOfNums+1, 0);
vector<int> min(nOfNums+1, 0);
int minval = 2100000000;
for (int n = 0; n < nOfNums; n++) {
    int num; cin >> num;
    if (minval > num) minval = num;
    if (num-minval > dptable[n]) dptable[n+1] = num-minval;
    else dptable[n+1] = dptable[n];
}
for (int n = 1; n <= nOfNums; n++) {
    cout << dptable[n] << " ";
}
////////////////////////////////////////////
return 0;}
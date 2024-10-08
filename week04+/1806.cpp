// https://www.acmicpc.net/problem/1806
// 부분합

// 문제
// 10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다.
// 이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)가 주어진다.
// 둘째 줄에는 수열이 주어진다. 수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 자연수이다.

// 출력
// 첫째 줄에 구하고자 하는 최소의 길이를 출력한다. 만일 그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다.

// 예제 입력 1 
// 10 15
// 5 1 3 5 10 7 4 9 2 8
// 예제 출력 1 
// 2

#include <iostream>
#include <vector>
using namespace std;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
///////////////////////////////////////////////////////
int nOfNums, s; cin >> nOfNums >> s;
vector<int> nums(nOfNums);
for (int n = 0; n < nOfNums; n++) cin >> nums[n];
int total = 0;
for (int n = 0; n < nOfNums; n++) total += nums[n];
if (total < s) {cout << 0; return 0;}
int sum = 0;
int length = 0;
int idx = 0;
int minval = 10000000;
for (int n = 0; n < nOfNums; n++) {
    sum += nums[n];
    ++length;
    while (sum-nums[idx] >= s) {
        sum -= nums[idx];
        --length;
        ++idx;
    }
    if (sum >= s && minval > length) minval = length;
}
cout << minval;
///////////////////////////////////////////////////////
return 0;}
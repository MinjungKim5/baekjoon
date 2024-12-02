// https://www.acmicpc.net/problem/2230
// 수 고르기

// 문제
// N개의 정수로 이루어진 수열 A[1], A[2], …, A[N]이 있다.
// 이 수열에서 두 수를 골랐을 때(같은 수일 수도 있다), 그 차이가 M 이상이면서 제일 작은 경우를 구하는 프로그램을 작성하시오.
// 예를 들어 수열이 {1, 2, 3, 4, 5}라고 하자. 만약 M = 3일 경우, 1 4, 1 5, 2 5를 골랐을 때 그 차이가 M 이상이 된다.
// 이 중에서 차이가 가장 작은 경우는 1 4나 2 5를 골랐을 때의 3이 된다.

// 입력
// 첫째 줄에 두 정수 N, M이 주어진다. 다음 N개의 줄에는 차례로 A[1], A[2], …, A[N]이 주어진다.

// 출력
// 첫째 줄에 M 이상이면서 가장 작은 차이를 출력한다. 항상 차이가 M이상인 두 수를 고를 수 있다.

// 제한
// 1 ≤ N ≤ 100,000
// 0 ≤ M ≤ 2,000,000,000
// 0 ≤ |A[i]| ≤ 1,000,000,000
// 예제 입력 1 
// 3 3
// 1
// 5
// 3
// 예제 출력 1 
// 4

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main () {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
////////////////////////////////////////
long long nOfNums, m; cin >> nOfNums >> m;
vector<long long> nums(nOfNums,0);
for (long long n = 0; n < nOfNums; n++) {
    cin >> nums[n];
}
sort(nums.begin(),nums.end());
long long p1 = 0, p2 = 1;
long long minval = 3000000000;
while (true) {
    if (p2 == nOfNums-1 && nums[p2]-nums[p1] < m) break;
    if (nums[p2]-nums[p1] == m) {cout << m; return 0;}
    if (nums[p2]-nums[p1] > m) {
        if (minval > nums[p2]-nums[p1]) minval = nums[p2]-nums[p1];
        p1++;
    }
    else p2++;
}
cout << minval;
////////////////////////////////////////
return 0;}
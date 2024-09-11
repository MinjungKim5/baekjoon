// https://www.acmicpc.net/problem/11444
// 피보나치 수 6

// 문제
// 피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.
// 이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다.
// n=17일때 까지 피보나치 수를 써보면 다음과 같다.
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
// n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 n이 주어진다. n은 1,000,000,000,000,000,000보다 작거나 같은 자연수이다.

// 출력
// 첫째 줄에 n번째 피보나치 수를 1,000,000,007으로 나눈 나머지를 출력한다.

// 예제 입력 1 
// 1000
// 예제 출력 1 
// 517691607

#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

vector<long long> fiboMatrix = {0, 1, 1, 1};
vector<long long> mm (vector<long long> a, vector<long long> b) {
    vector<long long> ret(4);
    ret[0] = (a[0]*b[0]+a[1]*b[2])%MOD;
    ret[1] = (a[0]*b[1]+a[1]*b[3])%MOD;
    ret[2] = (a[2]*b[0]+a[3]*b[2])%MOD;
    ret[3] = (a[2]*b[1]+a[3]*b[3])%MOD;
    return ret;
}
vector<long long> mp (vector<long long> a, long long n) {
    if (n == 1) return a;
    vector<long long> msqr = mm(a,a);
    if (n%2) return mm(mp(msqr, n/2),a);
    else return mp(msqr, n/2);
}

int main() {
    long long n; cin >> n;
    cout << mp(fiboMatrix, n)[2];
return 0;}
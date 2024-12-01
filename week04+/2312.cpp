// https://www.acmicpc.net/problem/2312
// 수 복원하기

// 문제
// 양의 정수 N이 주어졌을 때, 이 수를 소인수분해 한 결과를 출력하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 테스트 케이스의 수가 주어진다. 각 테스트 케이스마다 양의 정수 N (2 ≤ N ≤ 100,000)이 주어진다.

// 출력
// 각 테스트 케이스마다 각 인수와 그 인수가 곱해진 횟수를 한 줄씩 출력한다. 출력 순서는 인수가 증가하는 순으로 한다.

// 예제 입력 1 
// 2
// 6
// 24
// 예제 출력 1 
// 2 1
// 3 1
// 2 3
// 3 1

#include <iostream>
#include <vector>
using namespace std;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//////////////////////////////////////////////////
vector <int> primes = {2};
for (int i = 3; i < 100000; i++) {
    bool na = true;
    for (int p : primes) {
        if (p*p > i) break;
        if (i%p == 0) {
            na = false;
            break;
        }
    }
    if (na) {
        primes.push_back(i);
    }
}
int psize = primes.size();
int testcase; cin >> testcase;
for (int t = 0; t < testcase; t++) {
    vector<int> count(primes.size(), 0);
    int q; cin >> q;
    for (int i = 0; i < psize; i++) {
        int prime = primes[i];
        while (q%prime==0) {
            count[i]++;
            q = q/prime;
        }
        if (q == 1) break;
    }
    for (int i = 0; i < psize; i++) {
        if (count[i] > 0) {
            cout << primes[i] << " " << count[i] << "\n";
        }
    }
}
//////////////////////////////////////////////////
return 0;}
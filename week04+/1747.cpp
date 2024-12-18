// https://www.acmicpc.net/problem/1747
// 소수&팰린드롬

// 문제
// 어떤 수와 그 수의 숫자 순서를 뒤집은 수가 일치하는 수를 팰린드롬이라 부른다. 예를 들어 79,197과 324,423 등이 팰린드롬 수이다.
// 어떤 수 N (1 ≤ N ≤ 1,000,000)이 주어졌을 때, N보다 크거나 같고, 소수이면서 팰린드롬인 수 중에서, 가장 작은 수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N이 주어진다.

// 출력
// 첫째 줄에 조건을 만족하는 수를 출력한다.

// 예제 입력 1 
// 31
// 예제 출력 1 
// 101

#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    if (n == 1) {cout << 2; return 0;}
    vector<int> primes = {2};
    for(int num = 3; num < 1001; num++) {
        bool sosu = true;
        for (int prime: primes) {
            if (prime*prime > num) break;
            if (num % prime == 0) {sosu = false; break;}
        }
        if (!sosu) continue;
        primes.push_back(num);
    }
    while (true) {
        string numString = to_string(n);
        int len = numString.size();
        bool palindrome = true;
        for (int i = 0; i < len; i++) {
            if (numString[i] != numString[len-1-i]) {palindrome = false; break;}
        }
        if (!palindrome) {n++; continue;}
        bool sosu = true;
        for (int prime: primes) {
            if (n == prime) {cout << n; return 0;}
            if (n%prime == 0) {sosu = false; break;}
        }
        if (!sosu) {n++; continue;}
        cout << n; return 0;
    }
}
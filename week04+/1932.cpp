// https://www.acmicpc.net/problem/1932
// 정수 삼각형

#include <vector>
#include <iostream>
using namespace std;

int main() {
////////////////////////////////////////
int n_of_tri; cin >> n_of_tri;
if (n_of_tri == 1) {int a; cin >> a; cout << a; return 0;}
vector<int> res(n_of_tri, 0);
for (int n = 0; n < n_of_tri; n++) {
    vector<int> newres(n+1, 0);
    // 입력 받은 자리의 수 + min(res[i], res[i-1]
    for (int i = 0; i < n+1; i++) {
        int num_i; cin >> num_i;
        if (i==0) newres[i] = res[i] + num_i;
        else res[i] > res[i-1]? newres[i] = res[i] + num_i : newres[i] = res[i-1] + num_i;
    }
    for (int i = 0; i < n+1; i++) res[i] = newres[i];
}

int max = 0;
for (int i = 0; i < n_of_tri; i++) {
    if (res[i] > max) max = res[i];
}
cout << max;
////////////////////////////////////////
return 0;}
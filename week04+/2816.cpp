// https://www.acmicpc.net/problem/2816
// 디지털 티비

#include <iostream>
using namespace std;

int main() {
//////////////////////////////////////
int kbs1 = 0, kbs2 = 0;
int count = 0;
while (kbs1 == 0 || kbs2 == 0) {
    string channel; cin >> channel;
    if (channel == "KBS1") kbs1 = count;
    else if (channel == "KBS2") kbs2 = count;
    count++;
}
if (kbs1 < kbs2) {
    for (int i = 1; i < kbs1; i++) cout << "1";
    for (int i = 1; i < kbs1; i++) cout << "4";
    for (int i = 1; i < kbs2; i++) cout << "1";
    for (int i = 1; i < kbs2-1; i++) cout << "4";
}
else {
    for (int i = 1; i < kbs2; i++) cout << "1";
    for (int i = 1; i < kbs2; i++) cout << "4";
    for (int i = 1; i < kbs1; i++) cout << "1";
    for (int i = 1; i < kbs1; i++) cout << "4";
}
//////////////////////////////////////
return 0;}
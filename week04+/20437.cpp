// https://www.acmicpc.net/problem/20437
// 문자열 게임 2

// 문제
// 작년에 이어 새로운 문자열 게임이 있다. 게임의 진행 방식은 아래와 같다.

// 알파벳 소문자로 이루어진 문자열 W가 주어진다.
// 양의 정수 K가 주어진다.
// 어떤 문자를 정확히 K개를 포함하는 가장 짧은 연속 문자열의 길이를 구한다.
// 어떤 문자를 정확히 K개를 포함하고, 문자열의 첫 번째와 마지막 글자가 해당 문자로 같은 가장 긴 연속 문자열의 길이를 구한다.
// 위와 같은 방식으로 게임을 T회 진행한다.

// 입력
// 문자열 게임의 수 T가 주어진다. (1 ≤ T ≤ 100)
// 다음 줄부터 2개의 줄 동안 문자열 W와 정수 K가 주어진다. (1 ≤ K ≤ |W| ≤ 10,000) 

// 출력
// T개의 줄 동안 문자열 게임의 3번과 4번에서 구한 연속 문자열의 길이를 공백을 사이에 두고 출력한다.
// 만약 만족하는 연속 문자열이 없을 시 -1을 출력한다.

// 예제 입력 1 
// 2
// superaquatornado
// 2
// abcdefghijklmnopqrstuvwxyz
// 5
// 예제 출력 1 
// 4 8
// -1

#include <iostream>
#include <vector>
using namespace std;

int main() {
///////////////////////////////////////////////
int testcase; cin >> testcase;
for (int t = 0; t < testcase; t++) {
    string instr; cin >> instr;
    vector<vector<int>> alphabet(26);
    for (int i = 0; i < instr.size(); i++) {
        alphabet[instr[i]-97].push_back(i);
    }
    
    int repeat; cin >> repeat;
    if (repeat == 1) {cout << "1 1" << "\n"; continue;}
    int minval = 20000, maxval = 0;
    for (int a = 0; a < 26; a++) {
        if (alphabet[a].size() < repeat) continue;
        for (int i = 0; i < alphabet[a].size()-repeat+1; i++) {
            int length = alphabet[a][i+repeat-1]-alphabet[a][i]+1;
            if (minval > length) minval = length;
            if (maxval < length) maxval = length;
        }
    }
    if (minval == 20000) cout << -1 << "\n";
    else cout << minval << " " << maxval << "\n";
}
///////////////////////////////////////////////
return 0;}
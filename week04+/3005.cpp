// https://www.acmicpc.net/problem/3005
// 크로스워드 퍼즐 쳐다보기

// 문제
// 크로스워드 퍼즐은 R*C크기의 직사각형으로 이루어져 있고, 각 칸은 비어있거나 막혀있다.
// 퍼즐은 가로(왼쪽->오른쪽) 또는 세로(위->아래)로 연속된 빈 칸에 단어를 채우면서 푼다.
// 동혁이는 크로스워드 퍼즐을 풀지 않는다. 그는 풀려있는 퍼즐을 쳐다본다.
// 그런 후에, 그는 그 퍼즐에서 사전순으로 제일 앞서는 단어를 찾는다.(단어는 적어도 2글자이다.)
// 크로스워드 퍼즐이 주어졌을 때, 사전순으로 제일 앞서는 단어를 출력하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 R과 C (2 ≤ R, C ≤ 20)가 주어진다. R는 행의 개수, C는 열의 개수이다.
// 그 다음 R개의 줄엔 C개의 문자가 포함되어 있다. 각 문자는 영어 알파벳 소문자 또는 '#'이며, '#'인 경우에는 막혀있는 것이다.

// 출력
// 첫째 줄에 사전순으로 제일 앞서는 단어를 출력한다. 정답이 항상 존재하는 경우만 입력으로 주어진다.

// 예제 입력 1 
// 4 4
// luka
// o#a#
// kula
// i#a#
// 예제 출력 1 
// kala
// 예제 입력 2 
// 4 4
// luka
// o#a#
// kula
// i#as
// 예제 출력 2 
// as
// 예제 입력 3 
// 4 5
// adaca
// da##b
// abb#b
// abbac
// 예제 출력 3 
// abb

#include <vector>
#include <iostream>
using namespace std;

int main() {
/////////////////////////////////////
int vertical, horizontal; cin >> vertical >> horizontal;
vector<vector<char>> map(vertical+2, vector<char>(horizontal+2, '#'));
for (int v = 1; v <= vertical; v++) {
    for (int h = 1; h <= horizontal; h++) {
        cin >> map[v][h];
    }
}
string res = "zzzzzzzzzzzzzzzzzzzzzzzzzzzz";
for (int v = 1; v <= vertical; v++) {
    for (int h = 1; h <= horizontal; h++) {
        if (map[v][h] == '#') continue;
        // 가로
        if (map[v][h-1] =='#') {
            string g = "";
            for (int i = h; map[v][i]!='#'; i++) {
                if (map[v][h-1]!='#') break;
                g.push_back(map[v][i]);
            }
            if (g.size()>1 && g < res) res = g;
        }
        // 세로
        if (map[v-1][h] =='#') {
            string s = "";
            for (int i = v; map[i][h]!='#'; i++) {
                s.push_back(map[i][h]);
            }
            if (s.size()>1 && s < res) res = s;
        }
        // 대각선
        // if (map[v-1][h-1] == '#') {
        //     string d = "";
        //     for (int i = 0; map[v+i][h+i]!='#'; i++) {
        //         d.push_back(map[v+i][h+i]);
        //     }
        //     if (d.size()>1 && d < res) res = d;
        // }
    }
}
cout << res;
/////////////////////////////////////
return 0;}
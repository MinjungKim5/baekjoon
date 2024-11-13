// https://www.acmicpc.net/problem/9177
// 단어 섞기

// 문제
// 세 개의 단어가 주어졌을때, 꿍은 첫 번째 단어와 두 번째 단어를 섞어서 세 번째 단어를 만들 수 있는지 궁금해졌다.
// 첫 번째와 두 번째 단어는 마음대로 섞어도 되지만 원래의 순서는 섞여서는 안 된다. 다음과 같은 경우를 생각해보자.
// 첫 번째 단어 : cat
// 두 번째 단어 : tree
// 세 번째 단어 : tcraete
// 보면 알 수 있듯이, 첫 번째 단어와 두 번째 단어를 서로 섞어서 세 번째 단어를 만들 수 있다. 아래와 같이 두 번째 예를 들어보자.
// 첫 번째 단어 : cat
// 두 번째 단어 : tree
// 세 번째 단어 : catrtee
// 이 경우 역시 가능하다. 그렇다면 "cat"과 "tree"로 "cttaree"를 형성하는건 불가능하다는걸 눈치챘을 것이다.

// 입력
// 입력의 첫 번째 줄에는 1부터 1000까지의 양의 정수 하나가 주어지며 데이터 집합의 개수를 뜻한다.
// 각 데이터집합의 처리과정은 동일하다고 하자. 각 데이터집합에 대해, 세 개의 단어로 이루어져 있으며 공백으로 구분된다.
// 모든 단어는 대문자 또는 소문자로만 구성되어 있다.
// 세 번째 단어의 길이는 항상 첫 번째 단어와 두 번째 단어의 길이의 합이며 첫 번째 단어와 두 번째 단어의 길이는 1~200이다.

// 출력
// 각 데이터집합에 대해 다음과 같이 출력하라.
// 만약 첫 번째 단어와 두 번째 단어로 세 번째 단어를 형성할 수 있다면
// Data set n: yes 과 같이 출력하고 
// 만약 아니라면 Data set n: no 과 같이 출력하라. 물론 n은 데이터집합의 순번으로 바뀌어야 한다. 아래의 예제 출력을 참고하라.

// 예제 입력 1 
// 3
// cat tree tcraete
// cat tree catrtee
// cat tree cttaree
// 예제 출력 1 
// Data set 1: yes
// Data set 2: yes
// Data set 3: no

#include <vector>
#include <iostream>
using namespace std;

string canMakeIt() {
    string a, b, c; cin >> a >> b >> c;
    int sizea = a.size();
    int sizeb = b.size();
    vector<vector<bool>> dptable(sizea+2,vector<bool>(sizeb+2,false));
    dptable[0][0] = true;
    for (int i = 1; i <= c.size(); i++) {
        char standard = c[i-1];
        bool possible = false;
        for (int j = 0; j < i && j <=sizea; j++) {
            if (i-1-j > sizeb) continue;
            if (!dptable[j][i-1-j]) continue;
            if (standard == a[j]) {dptable[j+1][i-1-j] = true; possible = true;}
            if (standard == b[i-1-j]) {dptable[j][i-j] = true; possible = true;}
        }
        if (!possible) return "no";
    }
    return "yes";
}

int main() {
    int testcase; cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        string result = canMakeIt();
        cout << "Data set " << t << ": " << result << "\n";
    }
return 0;}
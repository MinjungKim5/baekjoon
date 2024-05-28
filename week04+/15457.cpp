// https://www.acmicpc.net/problem/16457
// 단풍잎 이야기

// 문제
// 리유나와 라가는 메이플스토리라는 노동을 즐겨 한다. 메이플스토리에서는 키셋팅을 할 수 있는데, 키셋팅을 하면 원하는 키를 눌러서 원하는 스킬을 쓰게 할 수 있다.
// 리유나와 라가는 원래 좋은 친구였다. 리유나는 레벨이 225인데, 라가는 레벨이 202밖에 되지 않는다.
// 라가는 리유나를 질투해서 메이플 레벨을 따라잡으려고 했다. 그래서 리유나가 메이플을 하지 못하도록 키보드에 있는 키를 n개만 빼고 모두 망가뜨려버렸다!
// 하지만 리유나는 메이플에 이미 인생을 팔아버렸기 때문에, 키가 망가져도 일간 퀘스트를 계속해야만 했다!
// 그래서 2n개의 스킬들 중에서 n개를 적절히 키에 배치해서 어떻게든 일간 퀘스트를 해야만 했다!
// 일간 퀘스트는 다음과 같이 진행된다. m개의 퀘스트들이 주어진다. 각각의 퀘스트에서는 k개의 스킬을 사용해야 한다.
// 만약 스킬을 사용할 수 없다면 그 퀘스트는 수행할 수 없다고 본다.
// 리유나는 n개의 키에 스킬들을 배치하려고 한다. 실제 게임에서는 키셋팅을 마음대로 할 수 있고, 키셋팅을 하지 않아도 더블 클릭으로 스킬을 사용할 수 있지만,
// 여기서는 키셋팅을 한번 설정하면 그 날은 키셋팅을 다시 바꿀 수 없고 더블 클릭으로 스킬을 사용할 수 없다고 가정하다.
// 이 때 어떤 스킬들을 배치해야 가장 많은 양의 일간 퀘스트를 깰 수 있는지 구하자.

// 입력
// 첫째 줄에 키의 개수 n, 퀘스트의 개수 m, 퀘스트 당 사용해야 하는 스킬의 수 k가 주어진다. n은 10 이하, k는 n 이하의 양의 정수이며, m은 100 이하의 양의 정수이다.
// 둘째 줄부터 m개의 줄에는 각각의 퀘스트에서 사용해야 하는 스킬들이 나온다. 스킬들의 이름은 1에서 2n까지의 정수로 주어진다.

// 출력
// 첫째 줄에 가장 최적의 키배치를 했을 때 최대로 깰 수 있는 퀘스트의 개수를 출력한다.

// 예제 입력 1 
// 3 4 2
// 1 3
// 1 2
// 2 3
// 3 6
// 예제 출력 1 
// 3

#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

// 스킬셋과 퀘스트가 일치되는지 확인
int nogada(int skillset, vector<int> quests) {
    vector<int>::iterator iter;
    int count = 0;
    for (iter = quests.begin(); iter != quests.end(); iter++) {
        if ((*iter & skillset) == *iter) count++; 
    }
    return count;
}

void combination(int n_of_keys, int depth, int count, int num, set<int> *combi) {
    if (depth == 2*n_of_keys +1) return;

    if (count == n_of_keys) {
        (*combi).insert(num);
        return;
    }
    combination(n_of_keys, depth+1, count, num, combi);
    num += pow(2,depth);
    count += 1;
    combination(n_of_keys, depth+1, count, num, combi);
}

int main() {
/////////////////////////////////
int n_of_keys, m_of_quests, k_of_skills;
cin >> n_of_keys >> m_of_quests >> k_of_skills;

vector<int> quests(m_of_quests, 0);
for(int m = 0; m < m_of_quests; m++) {
    for (int k = 0; k < k_of_skills; k++) {
        int req_skill;
        cin >> req_skill;
        quests[m] += pow(2, req_skill-1);
    }
}
int maxcount = 0;


set<int> combi;
combination(n_of_keys, 0, 0, 0, &combi);
// 2n 가지 스킬들 중에서 n개 골라 스킬셋 세팅
// for (int i = 0; i < pow(2, 2*n_of_keys); i++) {
//     int kcount = 0;
//     int remain = i;
//     for (int j = 0; j < 2*n_of_keys; j++) {
//         kcount += remain%2;
//         remain = remain/2;
//     }
//     if (kcount == n_of_keys) combi.insert(i);
// };

set<int>::iterator setitr;
for (setitr = combi.begin(); setitr != combi.end(); setitr++) {
    int res = nogada(*setitr, quests);
    if (res > maxcount) maxcount = res;
}

cout << maxcount;

/////////////////////////////////
return 0;}
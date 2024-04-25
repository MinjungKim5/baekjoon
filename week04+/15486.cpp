// https://www.acmicpc.net/problem/15486
// 퇴사 2

// 문제
// 상담원으로 일하고 있는 백준이는 퇴사를 하려고 한다.
// 오늘부터 N+1일째 되는 날 퇴사를 하기 위해서, 남은 N일 동안 최대한 많은 상담을 하려고 한다.
// 백준이는 비서에게 최대한 많은 상담을 잡으라고 부탁을 했고, 비서는 하루에 하나씩 서로 다른 사람의 상담을 잡아놓았다.
// 각각의 상담은 상담을 완료하는데 걸리는 기간 Ti와 상담을 했을 때 받을 수 있는 금액 Pi로 이루어져 있다.
// N = 7인 경우에 다음과 같은 상담 일정표를 보자.

//  	1일	2일	3일	4일	5일	6일	7일
// Ti	3	5	1	1	2	4	2
// Pi	10	20	10	20	15	40	200
// 1일에 잡혀있는 상담은 총 3일이 걸리며, 상담했을 때 받을 수 있는 금액은 10이다. 5일에 잡혀있는 상담은 총 2일이 걸리며, 받을 수 있는 금액은 15이다.
// 상담을 하는데 필요한 기간은 1일보다 클 수 있기 때문에, 모든 상담을 할 수는 없다.
// 예를 들어서 1일에 상담을 하게 되면, 2일, 3일에 있는 상담은 할 수 없게 된다.
// 2일에 있는 상담을 하게 되면, 3, 4, 5, 6일에 잡혀있는 상담은 할 수 없다.
// 또한, N+1일째에는 회사에 없기 때문에, 6, 7일에 있는 상담을 할 수 없다.
// 퇴사 전에 할 수 있는 상담의 최대 이익은 1일, 4일, 5일에 있는 상담을 하는 것이며, 이때의 이익은 10+20+15=45이다.
// 상담을 적절히 했을 때, 백준이가 얻을 수 있는 최대 수익을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N (1 ≤ N ≤ 1,500,000)이 주어진다.

// 둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 50, 1 ≤ Pi ≤ 1,000)

// 출력
// 첫째 줄에 백준이가 얻을 수 있는 최대 이익을 출력한다.

// 예제 입력 1 
// 7
// 3 10
// 5 20
// 1 10
// 1 20
// 2 15
// 4 40
// 2 200
// 예제 출력 1 
// 45


#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {

int n_of_days;
cin >> n_of_days;
// jobs = {job0, job1 .... job(n-1)}
// job = {endday, startday, pay}
vector<vector<int>> jobs(n_of_days+1,vector<int>(3, 0));
for (int i = 1; i <= n_of_days; i++) {
    int man_day;
    int pay;
    cin >> man_day >> pay;
    int end_day = i + man_day - 1;
    jobs[i] = {end_day, pay};
}
// sort(jobs.begin(), jobs.end());

vector<int> p(n_of_days+2, 0);

for (int j = n_of_days; j > 0; j--) {
    if (jobs[j][0] > n_of_days) {
        p[j] = p[j+1];
        continue;
    }
    if (p[j+1] < (p[jobs[j][0]+1] + jobs[j][1])) p[j] = (p[jobs[j][0]+1] + jobs[j][1]);
    else p[j] = p[j+1];
    // cout << p[j] << endl;
}

cout << p[1];

}
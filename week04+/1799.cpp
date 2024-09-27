// https://www.acmicpc.net/problem/1799
// 비숍

// 문제
// 서양 장기인 체스에는 대각선 방향으로 움직일 수 있는 비숍(bishop)이 있다. 비숍은 대각선 방향으로 움직여 다른 말을 잡을 수 있다.
// 그런데 체스판 위에는 비숍이 놓일 수 없는 곳이 있다. 체스판에 0인 부분은 비숍이 놓일 수 없다고 하자.
// 정사각형 체스판의 한 변에 놓인 칸의 개수를 체스판의 크기라고 한다.
// 체스판의 크기와 체스판 각 칸에 비숍을 놓을 수 있는지 없는지에 대한 정보가 주어질 때,
// 서로가 서로를 잡을 수 없는 위치에 놓을 수 있는 비숍의 최대 개수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 체스판의 크기가 주어진다. 체스판의 크기는 10이하의 자연수이다.
// 둘째 줄부터 아래의 예와 같이 체스판의 각 칸에 비숍을 놓을 수 있는지 없는지에 대한 정보가 체스판 한 줄 단위로 한 줄씩 주어진다.
// 비숍을 놓을 수 있는 곳에는 1, 비숍을 놓을 수 없는 곳에는 0이 빈칸을 사이에 두고 주어진다.

// 출력
// 첫째 줄에 주어진 체스판 위에 놓을 수 있는 비숍의 최대 개수를 출력한다.

// 예제 입력 1 
// 5
// 1 1 0 1 1
// 0 1 0 0 0
// 1 0 1 0 1
// 1 0 0 0 0
// 1 0 1 1 1
// 예제 출력 1 
// 7

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<pair<int,int>> seated;
int maxval = 0;

void checkSeat (vector<pair<int,int>> seats, int ii) {
    if (maxval < seated.size()) maxval = seated.size();
    for (int i = ii; i < seats.size(); i++) {
        pair<int,int> seat = seats[i];
        bool available = true;
        for (pair<int,int>ban:seated) {
            int y = seat.first-ban.first;
            int x = seat.second-ban.second;
            if (abs(seat.first-ban.first) == abs(seat.second-ban.second)) {
                available = false;
                break;
            }
        }
        if (!available) continue;
        seats.erase(seats.begin()+i);
        int idx = seated.size();
        seated.push_back(seat);
        checkSeat(seats, i);
        seats.insert(seats.begin()+i, seat);
        seated.erase(seated.begin()+idx);
    }
}

int main() {
    int mapSize; cin >> mapSize;
    vector<pair<int,int>> seatsOdd;
    vector<pair<int,int>> seatsEven;
    for (int v = 0; v < mapSize; v++) {
        for (int h = 0; h < mapSize; h++) {
            int place; cin >> place;
            if (place) {
                if ((v+h)%2) seatsOdd.push_back({v,h});
                else seatsEven.push_back({v,h});
            }
        }
    }
    while (!seatsOdd.empty()) {
        seated.push_back(seatsOdd[0]);
        seatsOdd.erase(seatsOdd.begin());
        checkSeat(seatsOdd,0);
        seated.clear();
    }
    int maxvalOdd = maxval;
    maxval = 0;
    while (!seatsEven.empty()) {
        seated.push_back(seatsEven[0]);
        seatsEven.erase(seatsEven.begin());
        checkSeat(seatsEven,0);
        seated.clear();
    }
    cout << maxval+maxvalOdd;
}
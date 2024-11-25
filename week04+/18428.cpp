// https://www.acmicpc.net/problem/18428
// 감시 피하기

// 문제
// NxN 크기의 복도가 있다. 복도는 1x1 크기의 칸으로 나누어지며, 특정한 위치에는 선생님, 학생, 혹은 장애물이 위치할 수 있다.
// 현재 몇 명의 학생들은 수업시간에 몰래 복도로 빠져나왔는데, 복도로 빠져나온 학생들은 선생님의 감시에 들키지 않는 것이 목표이다.
// 각 선생님들은 자신의 위치에서 상, 하, 좌, 우 4가지 방향으로 감시를 진행한다.
// 단, 복도에 장애물이 위치한 경우, 선생님은 장애물 뒤편에 숨어 있는 학생들은 볼 수 없다.
// 또한 선생님은 상, 하, 좌, 우 4가지 방향에 대하여, 아무리 멀리 있더라도 장애물로 막히기 전까지의 학생들은 모두 볼 수 있다고 가정하자.
// 다음과 같이 3x3 크기의 복도의 정보가 주어진 상황을 확인해보자. 본 문제에서 위치 값을 나타낼 때는 (행,열)의 형태로 표현한다.
// 선생님이 존재하는 칸은 T, 학생이 존재하는 칸은 S, 장애물이 존재하는 칸은 O로 표시하였다.
// 학생들은 복도의 빈 칸 중에서 장애물을 설치할 위치를 골라, 정확히 3개의 장애물을 설치해야 한다.
// 결과적으로 3개의 장애물을 설치하여 모든 학생들을 감시로부터 피하도록 할 수 있는지 계산하고자 한다.
// NxN 크기의 복도에서 학생 및 선생님의 위치 정보가 주어졌을 때,
// 장애물을 정확히 3개 설치하여 모든 학생들이 선생님들의 감시를 피하도록 할 수 있는지 출력하는 프로그램을 작성하시오.
// 예를 들어 N=5일 때, 다음과 같이 선생님 및 학생의 위치 정보가 주어졌다고 가정하자.

// 입력
// 첫째 줄에 자연수 N이 주어진다. (3 ≤ N ≤ 6) 둘째 줄에 N개의 줄에 걸쳐서 복도의 정보가 주어진다.
// 각 행에서는 N개의 원소가 공백을 기준으로 구분되어 주어진다.
// 해당 위치에 학생이 있다면 S, 선생님이 있다면 T, 아무것도 존재하지 않는다면 X가 주어진다.
// 단, 전체 선생님의 수는 5이하의 자연수, 전체 학생의 수는 30이하의 자연수이며 항상 빈 칸의 개수는 3개 이상으로 주어진다.

// 출력
// 첫째 줄에 정확히 3개의 장애물을 설치하여 모든 학생들을 감시로부터 피하도록 할 수 있는지의 여부를 출력한다.
// 모든 학생들을 감시로부터 피하도록 할 수 있다면 "YES", 그렇지 않다면 "NO"를 출력한다.

// 예제 입력 1 
// 5
// X S X X T
// T X S X X
// X X X X X
// X T X X X
// X X T X X
// 예제 출력 1 
// YES

// 예제 입력 2 
// 4
// S S S T
// X X X X
// X X X X
// T T T X
// 예제 출력 2 
// NO

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

int main() {
    int size; cin >> size;
    vector<vector<char>> map(size, vector<char>(size,0));
    vector<pair<int,int>> teachers;
    vector<pair<int,int>> students;
    vector<pair<int,int>> xs;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'T') teachers.push_back({i,j});
            else if (map[i][j] == 'S') students.push_back({i,j});
            else xs.push_back({i,j});
        }
    }
    vector<vector<bool>> hazardMap(size,vector<bool>(size,false));
    for (pair<int,int> teacher: teachers) {
        for (int d = 0; d < 4; d++) {
            int i = 1;
            while (true) {
                int y = teacher.first + dir[d].first*i;
                int x = teacher.second + dir[d].second*i;
                if (y<0 || y>=size || x<0 || x>=size) break;
                if (map[y][x] == 'T') break;
                if (map[y][x] == 'S') {
                    if (i==1) {
                        cout << "NO";
                        return 0;
                    }
                    hazardMap[teacher.first + dir[d].first*(i-1)][teacher.second + dir[d].second*(i-1)] = true;
                    break;
                }
                i++;
            }
        }
    }

    vector<pair<int,int>> hazards;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (hazardMap[i][j]) hazards.push_back({i,j});
        }
    }
    // if (hazards.size() <= 3) {
    //     cout << "YES";
    //     return 0;
    // }
    int count = xs.size();
    for (int i = 0; i < count-2; i++) {
        for (int j = i+1; j < count-1; j++) {
            for (int k = j+1; k < count; k++) {
                vector<vector<int>> newmap(size,vector<int>(size,0));
                newmap[xs[i].first][xs[i].second] = 2;
                newmap[xs[j].first][xs[j].second] = 2;
                newmap[xs[k].first][xs[k].second] = 2;
                for (pair<int,int> student: students) {
                    newmap[student.first][student.second] = 1;
                }
                for (pair<int,int> teacher: teachers) {
                    newmap[teacher.first][teacher.second] = 2;
                }
                bool canSurvive = true;
                for (pair<int,int> teacher: teachers) {
                    for (int d = 0; d < 4; d++) {
                        int i = 1;
                        while (true) {
                            int y = teacher.first + dir[d].first*i;
                            int x = teacher.second + dir[d].second*i;
                            if (y<0 || y>=size || x<0 || x>=size) break;
                            if (newmap[y][x] == 2) break;
                            if (newmap[y][x] == 1) {
                                canSurvive = false;
                                break;
                            }
                            i++;
                        }
                    }
                }
                if (canSurvive) {cout << "YES"; return 0;}
            }
        }
    }
cout << "NO";
return 0;}
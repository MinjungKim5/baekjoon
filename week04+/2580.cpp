// https://www.acmicpc.net/problem/2580
// 스도쿠

#include <iostream>
#include <vector>
using namespace std;

bool completed = false;
vector<vector<int>> map(9,vector<int>(9,0));
vector<vector<bool>> horizontalPool(10,vector<bool>(10,true));
vector<vector<bool>> verticalPool(10,vector<bool>(10,true));
vector<vector<vector<bool>>> regionPool(3,vector<vector<bool>>(3,vector<bool>(10,true)));

void sudoku(int num) {
    if (num == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << map[i][j] << " ";
            }
            cout << "\n";
        }
        completed = true;
        return;
    }

    int i = num/9, j = num%9;
    if (map[i][j]) {
        sudoku(num+1);
        return;
    }

    for (int n = 1; n < 10; n++) {
        if (verticalPool[i][n] && horizontalPool[j][n] && regionPool[i/3][j/3][n]) {
            verticalPool[i][n] = false;
            horizontalPool[j][n] = false;
            regionPool[i/3][j/3][n] = false;
            map[i][j] = n;
            sudoku(num+1);
            if (completed) return;
            map[i][j] = 0;
            verticalPool[i][n] = true;
            horizontalPool[j][n] = true;
            regionPool[i/3][j/3][n] = true;
        }
    }
}

int main() {
/////////////////////////////////////
for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
        int num; cin >> num;
        map[i][j] = num;
        verticalPool[i][num] = false;
        horizontalPool[j][num] = false;
        regionPool[i/3][j/3][num] = false;
    }
}
sudoku(0);
/////////////////////////////////////
return 0;}
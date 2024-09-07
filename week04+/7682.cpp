// https://www.acmicpc.net/problem/7682
// 틱택토

#include <iostream>
using namespace std;

int position[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
bool winningCondition(string input, char ox) {
    for (int p = 0; p < 8; p++) {
        if (input[position[p][0]] == ox && input[position[p][1]] == ox && input[position[p][2]] == ox) return true;
    }
    return false;
}

int main(){
    while(true) {
        string input; cin >> input;
        if (input == "end") return 0;
        int countX = 0, countO = 0;
        for (int i = 0; i < 9; i++) {
            if (input[i] == 'X') countX++;
            else if (input[i] == 'O') countO++;
        }
        if (countX == countO+1 && winningCondition(input, 'X') && !winningCondition(input, 'O')) {
            cout << "valid\n";
        }
        else if (countX == countO && !winningCondition(input, 'X') && winningCondition(input, 'O')) {
            cout << "valid\n";
        }
        else if (countX == 5 && countO ==4 && !winningCondition(input, 'O')) cout << "valid\n";
        else cout << "invalid\n";
    }
}
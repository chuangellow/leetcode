#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkRow(int rowIdx, vector<vector<char>>& board) {
        int counter[10] = {0};
        for (int j = 0; j < 9; j++) {
            char c = board[rowIdx][j];
            if (c == '.') continue;
            if (counter[c - '0'] != 0) return false;
            counter[c - '0']++;
        }
        return true;
    }
    bool checkCol(int colIdx, vector<vector<char>>& board) {
        int counter[10] = {0};
        for (int i = 0; i < 9; i++) {
            char c = board[i][colIdx];
            if (c == '.') continue;
            if (counter[c - '0'] != 0) return false;
            counter[c - '0']++;
        }
        return true;
    }
    bool checkBox(int rowIdx, int colIdx, vector<vector<char>>& board) {
        int counter[10] = {0};
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j<= 1; j++) {
                char c = board[rowIdx+i][colIdx+j];
                if (c == '.') continue;
                if (counter[c - '0'] != 0) return false;
                counter[c - '0']++;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) if(!checkRow(i, board)) return false;
        for (int j = 0; j < 9; j++) if(!checkCol(j, board)) return false;
        pair<int, int> startPos = {1, 1};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!checkBox(startPos.first + 3*i, startPos.second + 3*j, board)) return false;
            }
        }
        return true;
    }
};

int main(void) {
    vector<vector<char>> board(9, vector<char>(9, '.'));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    Solution sol;
    cout << sol.isValidSudoku(board) << endl;
    return 0;
}
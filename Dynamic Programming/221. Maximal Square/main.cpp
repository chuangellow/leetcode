#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkValid(int row, int col, int squareLen, vector<vector<char>>& matrix) {
        for (int i = 0; i < squareLen; i++) {
            for (int j = 0; j < squareLen; j++) {
                if (matrix.at(row+i).at(col+j) == '0') return 0;
            } 
        }
        return 1;
    }
    void findMaxSize(int row, int col, int* maxSquareSize, vector<vector<char>>& matrix, const int m, const int n) {
        int len = 1;
        while (checkValid(row, col, len, matrix) && row + len < m && col + len < n) {
            len++;
        }
        len = checkValid(row, col, len, matrix)? len: len - 1;
        *maxSquareSize = max((len)*(len), *maxSquareSize);
        return;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxSquareSize = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                findMaxSize(i, j, &maxSquareSize, matrix, m, n);
            }
        }
        return maxSquareSize;
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> matrix(m, vector<char>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    Solution sol;
    cout << sol.maximalSquare(matrix) << endl;
    return 0;
}
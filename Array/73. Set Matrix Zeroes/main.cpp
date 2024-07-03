#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> rowSet;
        unordered_set<int> colSet;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rowSet.insert(i);
                    colSet.insert(j);
                }
            }
        }
        for (int row: rowSet) {
            for (int j = 0; j < n; j++) {
                matrix[row][j] = 0;
            }
        }
        for (int col: colSet) {
            for (int i = 0; i < m; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    Solution sol;
    sol.setZeroes(matrix);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
    }
    cout << endl;
    return 0;
}
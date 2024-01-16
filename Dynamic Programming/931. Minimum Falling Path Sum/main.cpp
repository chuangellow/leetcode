#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void findMinPathSum(int x, int y, int currentSum, int* minPathSum, vector<vector<int>>& matrix, const int n) {
        if (x >= n) {
            *minPathSum = min(currentSum, *minPathSum);
            return;
        }
        if (y - 1 >= 0) findMinPathSum(x+1, y-1, currentSum + matrix.at(x).at(y), minPathSum, matrix, n);
        if (y + 1 < n) findMinPathSum(x+1, y+1, currentSum + matrix.at(x).at(y), minPathSum, matrix, n);
        findMinPathSum(x+1, y, currentSum + matrix.at(x).at(y), minPathSum, matrix, n);
        return;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minPathSum = INT32_MAX;
        for (int i = 0; i < n; i++) {
            findMinPathSum(0, i, 0, &minPathSum, matrix, n);
        }
        return minPathSum;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    Solution sol;
    cout << sol.minFallingPathSum(matrix) << endl;
    return 0;
}
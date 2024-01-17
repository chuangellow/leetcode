#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dp(n, 0);
        vector<int> prevRow(n, 0);
        int maxValue = -1;
        for (int i = 0; i < n; i++) {
            prevRow[i] = (matrix[0][i] == '1');
            maxValue = max(prevRow[i], maxValue);
        }
        for (int i = 1; i < m; i++) {
            dp[0] = (matrix[i][0] == '1');
            maxValue = max(maxValue, dp[0]);
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '0') dp[j] = 0;
                else {
                    int minValue = min(dp[j-1], prevRow[j]);
                    minValue = min(minValue, prevRow[j-1]);
                    dp[j] = minValue + 1;
                    maxValue = max(maxValue, dp[j]);
                }
            }
            for (int j = 0; j < n; j++) {
                prevRow[j] = dp[j];
            }
        }
        return maxValue * maxValue;
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
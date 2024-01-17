#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) dp[i][0] = (matrix[i][0] == '1');
        for (int j = 0; j < n; j++) dp[0][j] = (matrix[0][j] == '1');
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else {
                    int minValue = min(dp[i-1][j], dp[i][j-1]);
                    minValue = min(minValue, dp[i-1][j-1]);
                    dp[i][j] = minValue + 1;
                }
            }
        }
        int maxValue = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxValue = max(maxValue, dp[i][j]);
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
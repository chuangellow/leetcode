#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++) dp[0][j] = matrix[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int minValue = INT32_MAX;
                if (j-1 >= 0) minValue = min(dp[i-1][j-1], minValue);
                if (j+1 < n) minValue = min(dp[i-1][j+1], minValue);
                minValue = min(dp[i-1][j], minValue);
                dp[i][j] = minValue + matrix[i][j];
            }
        }
        int minValue = INT32_MAX;
        for (int j = 0; j < n; j++) {
            minValue = min(minValue, dp[n-1][j]);
        }
        return minValue;
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
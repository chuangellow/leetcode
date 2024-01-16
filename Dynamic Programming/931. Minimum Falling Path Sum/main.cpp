#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) dp[i] = matrix[0][i];
        for (int i = 1; i < n; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                int minValue = INT32_MAX;
                if (j - 1 >= 0) minValue = min(minValue, dp[j-1]);
                if (j + 1 < n) minValue = min(minValue, dp[j+1]);
                minValue = min(minValue, dp[j]);
                temp[j] = minValue + matrix[i][j];
            }
            for (int j = 0; j < n; j++) {
                dp[j] = temp[j];
            }
        }
        int minValue = INT32_MAX;
        for (int i = 0; i < n; i++) {
            minValue = min(minValue, dp[i]);
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
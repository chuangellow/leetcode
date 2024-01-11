#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = (!obstacleGrid[0][0]);
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0] && (!obstacleGrid[i][0]);
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1] && (!obstacleGrid[0][j]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = (obstacleGrid[i][j])? 0: (dp[i-1][j] + dp[i][j-1]);
            }
        }
        return (obstacleGrid[m-1][n-1])? 0: dp[m-1][n-1];
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> obstacleGrid.at(i).at(j);
        }
    }
    Solution sol;
    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
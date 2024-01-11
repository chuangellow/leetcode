#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n);
        dp[0] = (!obstacleGrid[0][0]);
        for (int i = 1; i < n; i++) dp[i] = dp[i-1] && (!obstacleGrid[0][i]);
        for (int i = 1; i < m; i++) {
            int temp = dp[0] && (!obstacleGrid[i][0]);
            dp[0] = temp;
            for (int j = 1; j < n; j++) {
                temp = (obstacleGrid[i][j])? 0: temp + dp[j];
                dp[j] = temp;
            }
        }
        return (obstacleGrid[m-1][n-1])? 0: dp[n-1];
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
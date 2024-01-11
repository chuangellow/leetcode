#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
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
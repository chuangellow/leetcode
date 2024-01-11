#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void getNumPaths(int x, int y, int* numPaths, vector<vector<int>>& obstacleGrid, const int m, const int n) {
        if (x == m - 1 && y == n - 1) {
            *numPaths = *numPaths + 1;
            return;
        }
        if (x < m - 1 && !obstacleGrid[x+1][y]) {
            getNumPaths(x+1, y, numPaths, obstacleGrid, m, n);
        }
        if (y < n - 1 && !obstacleGrid[x][y+1]) {
            getNumPaths(x, y+1, numPaths, obstacleGrid, m, n);
        }
        return;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int numPaths = 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        getNumPaths(0, 0, &numPaths, obstacleGrid, m, n);
        return numPaths;
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
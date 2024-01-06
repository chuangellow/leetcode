#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void findMinSum(int currentM, int currentN, int sum, int* minSum, vector<vector<int>> grid, const int m, const int n) {
        if (currentM == m - 1 && currentN == n - 1) {
            sum += grid.at(m-1).at(n-1);
            *minSum = min(*minSum, sum);
            return;
        }
        if (currentM != m - 1) {
            int currentNum = grid.at(currentM).at(currentN);
            findMinSum(currentM+1, currentN, sum + currentNum, minSum, grid, m, n);
        }
        if (currentN != n - 1) {
            int currentNum = grid.at(currentM).at(currentN);
            findMinSum(currentM, currentN+1, sum + currentNum, minSum, grid, m, n);
        }
        return;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int minSum = INT32_MAX;
        int m = grid.size();
        int n = grid[0].size();
        findMinSum(0, 0, 0, &minSum, grid, m, n);
        return minSum;
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid.at(i).at(j);
        }
    }
    Solution sol;
    cout << sol.minPathSum(grid) << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += grid.at(0).at(i);
            dp.at(i) = sum;
        }
        sum = grid.at(0).at(0);
        for (int i = 1; i < m; i++) {
            sum += grid.at(i).at(0);
            int temp = sum;
            for (int j = 1; j < n; j++) {
                temp = min(dp.at(j), temp) + grid.at(i).at(j);
                dp.at(j) = temp;
            }
        }
        return dp.at(n-1);
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
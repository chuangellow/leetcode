#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += grid.at(0).at(i); 
            dp.at(0).at(i) = sum;
        }
        sum = 0;
        for (int i = 0; i < m; i++) {
            sum += grid.at(i).at(0);
            dp.at(i).at(0) = sum;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp.at(i).at(j) = min(dp.at(i-1).at(j), dp.at(i).at(j-1)) + grid.at(i).at(j);
            }
        }
        return dp.at(m-1).at(n-1);
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
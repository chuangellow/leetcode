#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp.at(0).at(i) = 1;
        }
        for (int i = 0; i < m; i++) {
            dp.at(i).at(0) = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp.at(i).at(j) = dp.at(i-1).at(j) + dp.at(i).at(j-1);
            }
        }
        return dp.at(m-1).at(n-1);
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    Solution sol;
    cout << sol.uniquePaths(m, n) << endl;
    return 0;
}
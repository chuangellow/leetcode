#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1; dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main(void) {
    int steps;
    cin >> steps;
    Solution sol;
    cout << sol.climbStairs(steps) << endl;
    return 0;
}
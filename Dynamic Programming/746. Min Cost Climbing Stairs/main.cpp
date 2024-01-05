#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 2) return min(cost.at(0), cost.at(1));
        vector<int> dp(n+1, 0);
        dp[0] = 0; dp[1] = cost.at(0); dp[2] = cost.at(1);
        for (int i = 3; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost.at(i - 1), dp[i - 2] + cost.at(i - 1));
        }
        return min(dp[n-1], dp[n]);
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost.at(i);
    }
    Solution sol;
    cout << sol.minCostClimbingStairs(cost) << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<vector<int>> dp(n+1, vector(n+1, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][i] = nums[i-1];
        }
        pair<int, int> start = {1, 2}, pos = start;
        while (!(pos.first == 1 && pos.second == n)) {
            int i = pos.first, j = pos.second;
            dp[i][j] = max(nums[i-1] + dp[i+1][j], dp[i][j-1] + nums[j-1]);
            if (pos.second == n) {
                start = {start.first, start.second+1};
                pos = start;
            }
            else {
                pos = {pos.first+1, pos.second+1};
            }
        }
        dp[1][n] = max(nums[0] + dp[2][n], dp[1][n-1] + nums[n-1]);
        int maxVal = INT32_MIN;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                maxVal = max(maxVal, dp[i][j]);
            }
        }
        return maxVal;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.maxSubArray(nums) << endl;
    return 0;
}
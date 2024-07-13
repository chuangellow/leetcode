#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        int maxVal = dp[1];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i-1] + nums[i-1], nums[i-1]);
            maxVal = max(dp[i], maxVal);
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
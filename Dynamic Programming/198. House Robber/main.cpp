#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums.at(0);
        vector<int> dp(n);
        dp[0] = nums.at(0); dp[1] = max(nums.at(0), nums.at(1));
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-2] + nums.at(i), dp[i-1]);
        }
        return dp[n-1];
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums.at(i);
    }
    Solution sol;
    cout << sol.rob(nums) << endl;
    return 0;
}
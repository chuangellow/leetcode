#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        vector<int> dp(n, 1);
        int finalMaxValue = 1;
        for (int i = 0; i < n; i++) {
            int maxValue = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) maxValue = max(maxValue, dp[j]);
            }
            dp[i] = maxValue + 1;
            finalMaxValue = max(finalMaxValue, dp[i]);
        }
        return finalMaxValue;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.lengthOfLIS(nums) << endl;
    return 0;
}
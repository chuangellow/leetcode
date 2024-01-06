#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxValue = -1;
        for (int i = 0; i < n; i++) {
            maxValue = max(nums.at(i), maxValue);
        }
        vector<int> table(maxValue+1, 0);
        for (int i = 0; i < n; i++) {
            table[nums.at(i)]++;
        }
        if (maxValue == 1) return table.at(1);
        vector<int> dp(maxValue+1, 0);
        dp[1] = table[1]; dp[2] = max(dp[1], 2 * table[2]);
        for (int i = 3; i <= maxValue; i++) {
            dp[i] = max(dp[i-2] + table[i] * i, dp[i-1]);
        }
        return dp[maxValue];
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
    cout << sol.deleteAndEarn(nums) << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> table(10001, 0);
        for (int i = 0; i < n; i++) {
            table[nums.at(i)]++;
        }
        vector<int> dp(10001, 0);
        dp[1] = table[1]; dp[2] = max(dp[1], 2 * table[2]);
        for (int i = 3; i <= 10000; i++) {
            dp[i] = max(dp[i-2] + table[i] * i, dp[i-1]);
        }
        return dp[10000];
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
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(int pos, vector<int>& nums, int sumA, int sumB, bool *ans) {
        if (pos == nums.size()) {
            if (sumA == sumB) *ans = true;
            return;
        }
        solve(pos+1, nums, sumA+nums[pos], sumB, ans);
        solve(pos+1, nums, sumA, sumB+nums[pos], ans);
        return;
    }
    bool canPartition(vector<int>& nums) {
        bool ans = false;
        solve(0, nums, 0, 0, &ans);
        return ans;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.canPartition(nums) << endl;
    return 0;
}
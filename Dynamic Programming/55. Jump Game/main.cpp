#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void jump(int pos, int n, vector<int>& nums, bool *ans) {
        if (pos >= n) return;
        if (pos == n-1) {
            *ans = true;
            return;
        }
        for (int i = 1; i <= nums[pos]; i++) {
            jump(pos + i, n, nums, ans);
        }
        return;
    }
    bool canJump(vector<int>& nums) {
        bool ans = false;
        jump(0, nums.size(), nums, &ans);
        return ans;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.canJump(nums) << endl;
    return 0;
}
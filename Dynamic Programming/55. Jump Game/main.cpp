#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> jumpToGoal(n, false);
        jumpToGoal[n-1] = true;
        int lastGoodIdx = n-1;
        for (int i = n-2; i >= 0; i--) {
            if (lastGoodIdx <= i + nums[i]) {
                jumpToGoal[i] = true;
                lastGoodIdx = i;
            }
        }
        return jumpToGoal[0];
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
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> cummulativeSum(n, 0);
        cummulativeSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            cummulativeSum[i] = nums[i] + cummulativeSum[i-1];
        }
        for (int i = 0; i < n; i++) {
            if (cummulativeSum[n-1] - cummulativeSum[i] == cummulativeSum[i]) return true;
        }
        return false;
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
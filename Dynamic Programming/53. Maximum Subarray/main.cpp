#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int prev = nums[0];
        int maxVal = prev;
        for (int i = 1; i < n; i++) {
            prev = max(prev + nums[i], nums[i]);
            maxVal = max(prev, maxVal);
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
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkIncreasing(vector<bool>& mask, vector<int>& nums, int n) {
        int temp = INT32_MIN;
        for (int i = 0; i < n; i++) {
            if (!mask[i]) continue;
            if (nums[i] <= temp) return false;
            temp = nums[i];
        }
        return true;
    }
    void getLenOfLIS(int pos, int* maxLen, vector<bool>& mask, vector<int>& nums, int n) {
        if (pos == n) {
            if (!checkIncreasing(mask, nums, n)) return;
            int len = 0;
            for (int i = 0; i < n; i++) len += (mask[i])? 1: 0;
            *maxLen = max(*maxLen, len);
            return;
        }
        mask[pos] = 0;
        getLenOfLIS(pos+1, maxLen, mask, nums, n);
        mask[pos] = 1;
        getLenOfLIS(pos+1, maxLen, mask, nums, n);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<bool> mask(n, true);
        int maxLen = -1;
        getLenOfLIS(0, &maxLen, mask, nums, n);
        return maxLen;
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
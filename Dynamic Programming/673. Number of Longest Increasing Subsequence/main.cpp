#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& subSequence, int len, int target) {
        int left = 0, right = len-1;
        while (left < right) {
            int mid = ((unsigned int) left + (unsigned int) right) >> 1;
            if (subSequence[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    int getLengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        vector<int> subSequence = {nums[0]};
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > subSequence[len-1]) {
                subSequence.push_back(nums[i]);
                len++;
            }
            else {
                int pos = binarySearch(subSequence, len, nums[i]);
                subSequence[pos] = nums[i];
            }
        }
        return len;
    }
    void getNumberOfLIS(int pos, int* count, vector<bool>& mask, vector<int>& nums, int n, int lengthOFLIS) {
        if (n == pos) {
            int temp = INT32_MIN;
            int currentLen = 0;
            for (int i = 0; i < n; i++) {
                if (!mask[i]) continue;
                if (nums[i] < temp) return;
                temp = nums[i];
                currentLen++;
            }
            if (currentLen == lengthOFLIS) *count = *count + 1;
            return;
        }
        mask[pos] = false;
        getNumberOfLIS(pos+1, count, mask, nums, n, lengthOFLIS);
        mask[pos] = true;
        getNumberOfLIS(pos+1, count, mask, nums, n, lengthOFLIS);
        return;
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int lengthOFLIS = getLengthOfLIS(nums);
        vector<bool> mask(n, true);
        int count = 0;
        getNumberOfLIS(0, &count, mask, nums, n, lengthOFLIS);
        return count;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.findNumberOfLIS(nums) << endl;
    return 0;
}
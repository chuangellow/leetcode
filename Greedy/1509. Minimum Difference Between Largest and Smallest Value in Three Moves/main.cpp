#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        vector<int> sortedNums(n);
        for (int i = 0; i < n; i++) sortedNums[i] = nums[i];
        sort(sortedNums.begin(), sortedNums.end());
        int minVal = INT32_MAX;
        for (int i = 0; i < 4; i++) {
            minVal = min(minVal, sortedNums[n-4+i]-sortedNums[i]);
        }
        return minVal;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.minDifference(nums) << endl;
    return 0;
}
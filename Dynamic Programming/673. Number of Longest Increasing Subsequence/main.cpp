#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lengthTable(n, 1);
        for (int i = 1; i < n; i++) {
            int maxValue = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i]) continue;
                maxValue = max(lengthTable[j], maxValue);
            }
            lengthTable[i] = maxValue + 1;
        }
        vector<int> numberTable(n, 1);
        for (int i = 1; i < n; i++) {
            int count = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i]) continue;
                if (lengthTable[j] == lengthTable[i] - 1) count += numberTable[j];
            }
            if (lengthTable[i] - 1 == 0) numberTable[i] = 1;
            else numberTable[i] = count;
        }
        int lenOfLIS = 0;
        for (int i = 0; i < n; i++) lenOfLIS = max(lenOfLIS, lengthTable[i]);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (lengthTable[i] == lenOfLIS) count += numberTable[i];
        }
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
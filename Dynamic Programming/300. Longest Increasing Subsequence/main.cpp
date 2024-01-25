#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
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
                int pos = -1;
                for (int j = 0; j < len; j++) {
                    if (subSequence[j] >= nums[i]) {
                        pos = j;
                        break;
                    }
                }
                subSequence[pos] = nums[i];
            }
        }
        return len;
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
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int left = 0, right = 0, n = nums.size();
        while (left < n && right < n) {
            while (right + 1 < n && nums[right+1] == nums[right]+1) {
                right += 1;
            }
            string s;
            if (left != right) {
                s = to_string(nums[left]) + "->" + to_string(nums[right]);
            }
            else {
                s = to_string(nums[left]);
            }
            left = right + 1;
            right = right + 1;
            result.push_back(s);
        }
        return result;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    vector<string> result = sol.summaryRanges(nums);
    for (string s: result) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
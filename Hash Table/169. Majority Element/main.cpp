#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (auto num: nums) {
                if (((1 << i) & num) != 0) {
                    count++;
                }
            }
            if (count > (n / 2)) ans |= (1 << i);
        }
        return ans;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.majorityElement(nums) << endl;
    return 0;
}
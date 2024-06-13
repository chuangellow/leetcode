#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.containsDuplicate(nums) << endl;
    return 0;
}
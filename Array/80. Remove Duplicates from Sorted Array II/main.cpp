#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int slow = 1, count = 1;
        for (int fast = 1; fast < n; fast++) {
            if (nums[fast] == nums[fast-1]) count += 1;
            else count = 1;
            if (count <= 2) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.removeDuplicates(nums) << endl;
    return 0;
}
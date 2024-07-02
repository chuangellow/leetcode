#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = 1;
        int lastElement = nums[0], count = 1;
        while (right < n) {
            if (nums[right] == lastElement) {
                count += 1;
            }
            else {
                lastElement = nums[right];
                count = 1;
            }
            if (count >= 3) {
                while (right < n && nums[right] == lastElement) right++;
                if (right == n) break;
                lastElement = nums[right];
                count = 1;
            }
            nums[left] = nums[right];
            left++;
            right++;
        }
        return left;
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
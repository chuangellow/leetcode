#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int vote = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            vote += (nums[i] == candidate)? 1: -1;
            if (vote == 0) {
                candidate = nums[i];
                vote = 1;
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate) count++;
            if (count > (n / 2)) return candidate;
        }
        return -1;
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
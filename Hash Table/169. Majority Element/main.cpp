#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            if (map.count(nums[i]) == 0) map[nums[i]] = 1;
            else map[nums[i]] += 1;
            if (map[nums[i]] > n / 2) return nums[i];
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
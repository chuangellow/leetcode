#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (map.count(nums[i]) != 0) {
                if (i - map[nums[i]] <= k) return true;
            }
            map[nums[i]] = i;
        }
        return false;
    }
};

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.containsNearbyDuplicate(nums, k) << endl;
    return 0;
}
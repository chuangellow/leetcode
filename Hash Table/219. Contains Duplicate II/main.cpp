#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> sortedNums(n);
        for (int i = 0; i < n; i++) sortedNums[i] = {nums[i], i};
        sort(sortedNums.begin(), sortedNums.end());
        pair<int, int> prevNum = sortedNums[0];
        for (int i = 1; i < n; i++) {
            if (sortedNums[i].first == prevNum.first && sortedNums[i].second - prevNum.second <= k) {
                return true;
            }
            prevNum = sortedNums[i];
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
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        unordered_set<int> set;
        for (int i = 0; i < n; i++) set.insert(nums[i]);
        int longestLen = 1;
        for (int i = 0; i < n; i++) {
            if (set.find(nums[i]-1) != set.end()) {
                continue;
            }
            int currentLen = 1;
            int currentNum = nums[i];
            while (set.find(currentNum+1) != set.end()) {
                currentLen += 1;
                currentNum += 1;
            }
            longestLen = max(longestLen, currentLen);
        }
        return longestLen;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.longestConsecutive(nums) << endl;
    return 0;
}
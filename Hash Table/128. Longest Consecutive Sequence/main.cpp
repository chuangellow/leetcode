#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> temp(n);
        for (int i = 0; i < n; i++) temp[i] = nums[i];
        sort(temp.begin(), temp.end());
        int currentLen = 1, longestLen = 1;
        int prev = temp[0];
        for (int i = 1; i < n; i++) {
            if (temp[i] == prev+1) {
                currentLen++;
                prev = temp[i];
            }
            else if (temp[i] != prev) {
                longestLen = max(longestLen, currentLen);
                currentLen = 1;
                prev = temp[i];
            }
        }
        longestLen = max(longestLen, currentLen);
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
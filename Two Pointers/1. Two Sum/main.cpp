#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(int start, vector<pair<int, int>>& nums, int target, int n) {
        int left = start, right = n-1;
        while (left <= right) {
            int mid = (unsigned int) (left + right) >> 1;
            if (nums.at(mid).first == target) return mid;
            else if (nums.at(mid).first > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        vector<pair<int, int>> temp(n);
        for (int i = 0; i < n; i++) {
            temp.at(i) = pair(nums.at(i), i);
        }
        sort(temp.begin(), temp.end());
        for (int i = 0; i < n; i++) {
            int idx = binarySearch(i+1, temp, target-temp.at(i).first, n);
            if (idx != -1) ans = {temp.at(i).second, temp.at(idx).second};
        }
        return ans;
    }
};

int main(void) {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums.at(i);
    }
    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);
    int ansSize = ans.size();
    for (int i = 0; i < ansSize; i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}
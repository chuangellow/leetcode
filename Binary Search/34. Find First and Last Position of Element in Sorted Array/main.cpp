#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchFirstIdx(vector<int>& nums, int target, int size) {
        int left = 0, right = size - 1;
        while (left < right) {
            int mid = (unsigned int) (left + right) >> 1;
            if (nums.at(mid) < target) left = mid + 1;
            else right = mid;
        }
        return (nums.at(right) == target)? right: -1;
    }
    int searchLastIdx(vector<int>& nums, int target, int size) {
        int left = 0, right = size - 1;
        while (left < right) {
            int mid = (unsigned int) (left + right + 1) >> 1;
            if (nums.at(mid) > target) right = mid - 1;
            else left = mid;
        }
        return (nums.at(right) == target)? right: -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(); 
        vector<int> ret(2);
        if (n < 1) {
            ret = {-1, -1};
            return ret;
        }
        int firstIdx = searchFirstIdx(nums, target, n);
        int LastIdx = searchLastIdx(nums, target, n);
        ret = {firstIdx, LastIdx};
        return ret;
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
    vector<int> ret = sol.searchRange(nums, target);
    cout << "[" << ret.at(0) << "," << ret.at(1) << "]" << endl;
    return 0;
}
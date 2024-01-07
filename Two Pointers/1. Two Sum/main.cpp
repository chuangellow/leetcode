#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> temp(n);
        for (int i = 0; i < n; i++) {
            temp.at(i) = pair(nums.at(i), i);
        }
        sort(temp.begin(), temp.end());
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = temp.at(left).first + temp.at(right).first;
            if (sum == target) return vector<int> {temp.at(left).second, temp.at(right).second};
            else if (sum > target) right--;
            else left++;
        }
        return vector<int> {};
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
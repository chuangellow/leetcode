#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums.at(i) + nums.at(j) == target) ans = {i, j};
            }
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
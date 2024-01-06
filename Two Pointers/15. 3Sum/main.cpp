#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums.at(i);
    }
    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);
    for (auto threeNums: ans) {
        for (auto num: threeNums) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
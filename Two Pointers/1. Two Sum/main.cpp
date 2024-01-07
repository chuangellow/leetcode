#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> table;
        for (int i = 0; i < n; i++) {
            if (table.find(target-nums.at(i)) != table.end()) {
                return vector<int> {table[target-nums.at(i)], i};
            }
            table[nums.at(i)] = i;
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
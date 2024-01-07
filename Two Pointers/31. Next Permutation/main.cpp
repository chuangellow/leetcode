#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums.at(i) < nums.at(i+1)) {
                int j = n - 1;
                while (nums.at(j) <= nums.at(i)) --j;
                swap(nums.at(i), nums.at(j));
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        return;
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
    sol.nextPermutation(nums);
    for (int i = 0; i < n; i++) {
        cout << nums.at(i) << " ";
    }
    cout << endl;
    return 0;
}
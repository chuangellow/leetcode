#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums.at(0);
        vector<int> dp(n);
        int firstNum = nums.at(0), secondNum = max(nums.at(0), nums.at(1));
        int result = 0;
        for (int i = 2; i < n; i++) {
            result = max(firstNum + nums.at(i), secondNum);
            firstNum = secondNum;
            secondNum = result;
        }
        return secondNum;
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
    cout << sol.rob(nums) << endl;
    return 0;
}
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long int sum = 0;
        int n = nums.size();
        if (n == 1) return false;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) return false;
        sum /= 2;
        vector<vector<bool>> table(n, vector<bool>(sum+1, false));
        if (nums[0] <= sum) table[0][nums[0]] = true;
        table[0][0] = true;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < sum+1; j++) {
                if (j >= nums[i]) {
                    table[i][j] = table[i-1][j] || table[i-1][j-nums[i]];
                }
                else {
                    table[i][j] = table[i-1][j];
                }
            }
        }
        return table[n-1][sum];
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.canPartition(nums) << endl;
    return 0;
}
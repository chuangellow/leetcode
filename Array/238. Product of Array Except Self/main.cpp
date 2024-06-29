#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int product = 1;
        int numZeros = 0, zeroIdx = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                numZeros += 1;
                zeroIdx = i;
            }
            if (numZeros >= 2) return ans;
            if (nums[i] != 0) product *= nums[i];
        }
        if (numZeros == 1) {
            ans[zeroIdx] = product;
            return ans;
        }
        ans[0] = 1;
        for (int i = 0; i < n-1; i++) ans[i+1] = ans[i] * nums[i];
        int suffixSum = 1;
        for (int i = n-1; i >= 0; i--) {
            ans[i] *= suffixSum;
            suffixSum *= nums[i];
        }
        return ans;
    }
};

int main(void) {
    int n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    return 0;
}
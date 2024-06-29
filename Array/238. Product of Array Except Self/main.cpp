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
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        for (int i = 0; i < n-1; i++) prefix[i+1] = prefix[i] * nums[i];
        for (int i = n-1; i >= 1; i--) suffix[i-1] = suffix[i] * nums[i];
        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
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
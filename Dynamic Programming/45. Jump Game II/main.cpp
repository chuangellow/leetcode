#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> jumps(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = nums[i]; j >= 1; j--) {
                if (i + j >= n) continue;
                if (jumps[i+j] == 0) {
                    jumps[i+j] = jumps[i] + 1; 
                }
                else jumps[i+j] = min(jumps[i+j], jumps[i] + 1);
            }
        }
        return jumps[n-1];
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.jump(nums) << endl;
    return 0;
}
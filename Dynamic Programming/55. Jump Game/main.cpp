#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= nums[i]; j++) {
                    if (i + j < n) {
                        visited[i+j] = true;
                    }
                }
            }
        }
        return visited[n-1];
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.canJump(nums) << endl;
    return 0;
}
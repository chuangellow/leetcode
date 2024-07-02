#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int numJumps = 0;
        int current = 0;
        while (current != n-1) {
            int maxVal = -1;
            int next = -1;
            for (int i = nums[current]; i >= 1; i--) {
                if (i + current == n-1) return numJumps + 1;
                if (i + current < n && (nums[i + current] + i) > maxVal) {
                    maxVal = (nums[i + current] + i);
                    next = i + current;
                }
            }
            numJumps += 1;
            current = next;
        }
        return numJumps;
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
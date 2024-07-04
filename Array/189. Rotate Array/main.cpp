#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = (k % n);
        if (k == 0) return;
        int count = 0;
        for (int start = 0; start < k; start++) {
            int idx = (start + k) % n, prev = nums[start];
            while (idx != start && count < n) {
                int temp = nums[idx];
                nums[idx] = prev;
                prev = temp;
                count++;
                idx = (idx + k) % n;
            }
            if (count >= n) return;
            int temp = nums[idx];
            nums[idx] = prev;
            prev = temp;
            count++;
        }
        return;
    }
};

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    sol.rotate(nums, k);
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;
    return 0;
}
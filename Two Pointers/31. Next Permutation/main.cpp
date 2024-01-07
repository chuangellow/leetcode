#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverse(int start, vector<int>& nums, const int n) {
        int left = start, right = n-1;
        while (left < right) {
            swap(nums.at(left++), nums.at(right--));
        }
        return;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums.at(i) < nums.at(i+1)) {
                int j = n - 1;
                for (; j > i; j--) {
                    if (nums.at(j) > nums.at(i)) {
                        swap(nums.at(i), nums.at(j));
                        break;
                    }
                }
                reverse(i+1, nums, n);
                break;
            }
            if (i == 0) reverse(i, nums, n);
        }
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
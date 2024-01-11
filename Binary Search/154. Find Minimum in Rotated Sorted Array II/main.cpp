#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPivot(vector<int>& nums, const int n) {
        if (nums.at(0) < nums.at(n-1)) return n-1;
        int left = 0, right = n-1;
        int rightMostNum = nums.at(n-1);
        while (left < right) {
            int mid = (unsigned int) (left + right + 1) >> 1;
            if (nums.at(mid) > rightMostNum) left = mid;
            else right = mid - 1;
        }
        return left;
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int pivot = findPivot(nums, n);
        return nums.at((pivot+1)%n);
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
    cout << sol.findMin(nums) << endl;
    return 0;
}
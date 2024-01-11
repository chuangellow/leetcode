#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPivot(int l, int r, vector<int>& nums, const int n) {
        if (nums.at(0) < nums.at(n-1)) return n-1;
        if (l == r) {
            if (l == n - 1) return -1;
            else if (nums.at(l) <= nums.at(l+1)) return -1;
            else return l;
        }
        int left = l, right = r;
        int rightMostNum = nums.at(n-1);
        while (left < right) {
            int mid = (unsigned int) (left + right + 1) >> 1;
            if (nums.at(mid) > rightMostNum) left = mid;
            else if (nums.at(mid) == rightMostNum) {
                int leftAns = findPivot(left, mid-1, nums, n);
                int rightAns = findPivot(mid, right, nums, n);
                if (leftAns == -1 && rightAns == -1) return -1;
                else if (leftAns != -1 && leftAns != n - 1) return leftAns;
                else if (rightAns != -1 && rightAns != n - 1) return rightAns;
                else return -1;
            }
            else right = mid - 1;
        }
        return left;
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int pivot = findPivot(0, n-1, nums, n);
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
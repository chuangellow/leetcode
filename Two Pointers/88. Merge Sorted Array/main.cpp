#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m - 1, index2 = n - 1, mergeIndex = m + n - 1;
        while (index1 >= 0 && index2 >= 0) {
            if (nums1[index1] > nums2[index2]) {
                nums1[mergeIndex--] = nums1[index1--];
            } else {
                nums1[mergeIndex--] = nums2[index2--];
            }
        }
        while (index2 >= 0) {
            nums1[mergeIndex--] = nums2[index2--];
        }
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m+n);
    for (int i = 0; i < m; i++) {
        cin >> nums1.at(i);
    }
    vector<int> nums2(n);
    for (int i = 0; i < n; i++) {
        cin >> nums2.at(i);
    }
    Solution sol;
    sol.merge(nums1, m, nums2, n);
    for (int i = 0; i < m + n; i++) {
        cout << nums1.at(i) << " ";
    }
    cout << endl;
    return 0;
}
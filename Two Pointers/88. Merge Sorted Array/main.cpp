#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m-1, ptr2 = n-1;
        int insertPtr = n+m-1;
        while (ptr1 >= 0 && ptr2 >= 0) {
            if (nums1.at(ptr1) > nums2.at(ptr2)) {
                nums1[insertPtr] = nums1[ptr1];
                ptr1--;
            }
            else {
                nums1[insertPtr] = nums2[ptr2];
                ptr2--;
            }
            insertPtr--;
        }
        while(insertPtr >= 0) {
            if (ptr1 >= 0) {
                nums1[insertPtr] = nums1[ptr1];
                ptr1--;
            }
            else if (ptr2 >= 0) {
                nums1[insertPtr] = nums2[ptr2];
                ptr2--;
            }
            insertPtr--;
        }
        return;
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
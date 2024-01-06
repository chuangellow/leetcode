#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m);
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
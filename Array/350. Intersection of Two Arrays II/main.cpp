#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1 = 0, p2 = 0;
        vector<int> result;
        while (p1 < n1 && p2 < n2) {
            while (p1 < n1 && p2 < n2 && nums1[p1] < nums2[p2]) p1++;
            while (p1 < n1 && p2 < n2 && nums2[p2] < nums1[p1]) p2++;
            while (p1 < n1 && p2 < n2 && nums1[p1] == nums2[p2]) {
                result.push_back(nums1[p1]);
                p1++;
                p2++;
            }
        }
        return result;
    }
};

int main(void) {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> nums1(n1);
    for (int i = 0; i < n1; i++) cin >> nums1[i];
    vector<int> nums2(n2);
    for (int i = 0; i < n2; i++) cin >> nums2[i];
    return 0;
}
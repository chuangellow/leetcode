#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> table;
        for (int i = 0; i < n1; i++) {
            table[nums1[i]]++;
        }
        vector<int> result;
        for (int i = 0; i < n2; i++) {
            if (table.count(nums2[i]) != 0 && table[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                table[nums2[i]]--;
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
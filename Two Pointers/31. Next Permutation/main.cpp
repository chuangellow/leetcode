#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
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
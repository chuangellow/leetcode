#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void getMaxMoney(int pos, int currentMoney, int* maxMoney, vector<int>& nums, const int n) {
        if (pos >= n) {
            *maxMoney = (currentMoney > *maxMoney)? currentMoney: *maxMoney;
            return;
        }
        getMaxMoney(pos+1, currentMoney, maxMoney, nums, n);
        getMaxMoney(pos+2, currentMoney + nums.at(pos), maxMoney, nums, n);
        return;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int maxMoney = -1;
        getMaxMoney(0, 0, &maxMoney, nums, n);
        return maxMoney;
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
    cout << sol.rob(nums) << endl;
    return 0;
}
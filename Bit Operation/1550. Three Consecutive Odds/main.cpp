#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int maxVal = arr[0];
        int n = arr.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 1) count += 1;
            else count = 0;
            if (count == 3) return true;
        }
        return false;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    cout << sol.threeConsecutiveOdds(nums) << endl;
    return 0;
}
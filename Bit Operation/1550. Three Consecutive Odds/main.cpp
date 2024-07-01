#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if (n <= 2) return false;
        int mask = 0;
        for (int i = 0; i < 3; i++) {
            int isOdd = (arr[i] % 2 == 1)? 1: 0;
            mask |= (isOdd << i);
        }
        if (mask == 7) return true;
        cout << mask << endl;
        for (int i = 3; i < n; i++) {
            mask &= ~(1);
            mask = mask >> 1;
            int isOdd = (arr[i] % 2 == 1)? 1: 0;
            mask |= (isOdd << 2);
            if (mask == 7) return true;
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
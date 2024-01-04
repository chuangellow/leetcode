#include <iostream>

using namespace std;

class Solution {
public:
    void countNumberWays(int current, int *ans, int n) {
        if (current > n) return;
        if (current == n) { 
            *ans = *ans + 1;
            return;
        }
        countNumberWays(current + 1, ans, n);
        countNumberWays(current + 2, ans, n);
    }
    int climbStairs(int n) {
        int ans = 0;
        countNumberWays(0, &ans, n);
        return ans;
    }
};

int main(void) {
    int steps;
    cin >> steps;
    Solution sol;
    cout << sol.climbStairs(steps) << endl;
    return 0;
}
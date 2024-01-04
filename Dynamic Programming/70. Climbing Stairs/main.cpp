#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
       if (n == 0 || n == 1) return 1;
       int prev = 1;
       int now = 1;
       int next = 0;
       for (int i = 2; i <= n; i++) {
        next = prev + now;
        prev = now;
        now = next;
       }
       return next;
    }
};

int main(void) {
    int steps;
    cin >> steps;
    Solution sol;
    cout << sol.climbStairs(steps) << endl;
    return 0;
}
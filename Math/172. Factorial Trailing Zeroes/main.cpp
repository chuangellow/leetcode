#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int fiveCount = 0;
        for (int i = 1; i <= n; i++) {
            int temp = i;
            while (temp > 0) {
                if (temp % 5 == 0) fiveCount++;
                else break;
                temp /= 5;
            }
        }
        return fiveCount;
    }
};

int main(void) {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.trailingZeroes(n) << endl;
    return 0;
}
#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int fiveCount = 0;
        int current = 5;
        while (current <= n) {
            int temp = current;
            while (temp > 0 && temp % 5 == 0) {
                fiveCount++;
                temp /= 5;
            }
            current += 5;
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
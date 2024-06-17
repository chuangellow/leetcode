#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(int left, int right, int target) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid * mid == target) return true;
            else if (mid * mid < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    bool judgeSquareSum(int c) {
        for (int i = 0; i <= (int) sqrt(c); i++) {
            if (binarySearch(0, sqrt(c), c - i * i) != -1) {
                return true;
            }
        }
        return false;
    }
};

int main(void) {
    int c;
    cin >> c;
    Solution sol;
    cout << sol.judgeSquareSum(c) << endl;
    return 0;
}
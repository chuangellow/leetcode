#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int number = 3;
        vector<int> temp = {0, 1, 1};
        int result = 0;
        for (int i = 3; i <= n; i++) {
            result = 0;
            for (int i = 0; i < number; i++) {
                result += temp.at(i);
            }
            for (int i = 0; i < number-1; i++) {
                temp[i] = temp[i+1];
            }
            temp[number-1] = result;
        }
        return result;
    }
};

int main(void) {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.tribonacci(n) << endl;
    return 0;
}
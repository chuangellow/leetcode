#include <iostream>

using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        if (n == 1) return 1;
        int pass = (time % (2 * (n - 1)));
        if (pass == 0) pass = (2 * (n - 1));
        if (pass <= ((n - 1))) {
            return pass + 1;
        }
        else {
            return (2 * (n - 1)) - pass + 1;
        }
    }
};

int main(void) {
    int n, time;
    cin >> n >> time;
    Solution sol;
    cout << sol.passThePillow(n, time) << endl;
    return 0;
}
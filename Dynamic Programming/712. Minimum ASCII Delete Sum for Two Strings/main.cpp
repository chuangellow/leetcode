#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void getMinDeleteSum(int deleteSum, int* minDeleteSum, string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if ((len1 == len2 && len1 == 0) || (len1 == len2 && s1 == s2)) {
            *minDeleteSum = min(*minDeleteSum, deleteSum);
            return;
        }
        for (int pos = 0; pos < len1; pos++) {
            string newS1 = s1;
            newS1.erase(pos, 1);
            getMinDeleteSum(deleteSum+int(s1.at(pos)), minDeleteSum, newS1, s2);
        }
        for (int pos = 0; pos < len2; pos++) {
            string newS2 = s2;
            newS2.erase(pos, 1);
            getMinDeleteSum(deleteSum+int(s2.at(pos)), minDeleteSum, s1, newS2);
        }
        return;
    }
    int minimumDeleteSum(string s1, string s2) {
        int minDeleteSum = INT32_MAX;
        getMinDeleteSum(0, &minDeleteSum, s1, s2);
        return minDeleteSum;
    }
};

int main(void) {
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol;
    cout << sol.minimumDeleteSum(s1, s2) << endl;
    return 0;
}
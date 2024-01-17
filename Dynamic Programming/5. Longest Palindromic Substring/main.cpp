#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkPalindrome(int left, int right, string s) {
        while (left <= right) {
            if (s.at(left) == s.at(right)) {
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int len = s.length();
        int maxLen = -1;
        string outStr;
        int start = -1, end = -1;
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                if (checkPalindrome(i, j, s)) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i, end = j;
                        cout << i << ' ' << j << endl;
                    }
                }
            }
        }
        if (start == -1 && end == -1) return s.substr(0, 1);
        return s.substr(start, end-start+1);
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}
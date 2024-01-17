#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string remove(string& s, char target) {
        string output;
        int start = 0, end = s.length();
        int insertIdx = 0;
        for (int i = 0; i < end; i++) {
            if (s.at(i) != target) {
                output.push_back(s.at(i));
                insertIdx++;
            }
        }
        return output;
    }
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 1) return s.substr(0, 1);
        if (len == 2) return (s[0] == s[1])? s.substr(0, 2): s.substr(0, 1);
        string strWithDelim;
        for (int i = 0; i < 2 * len + 1; i++) {
            if (i % 2 == 0) strWithDelim.push_back('*');
            else strWithDelim.push_back(s.at(i/2));
        }
        int maxLen = -1;
        int maxLeft = -1, maxRight = -1;
        for (int i = 0; i < 2 * len + 1; i++) {
            int currentLen = (strWithDelim[i] == '*')? 1 : 2;
            while (i - currentLen >= 0 && i + currentLen < 2 * len + 1) {
                if (strWithDelim[i-currentLen] == strWithDelim[i+currentLen]) {
                    if (2 * currentLen + 1 > maxLen) {
                        maxLen = 2 * currentLen + 1;
                        maxLeft = i - currentLen;
                        maxRight = i + currentLen;
                    }
                    currentLen += 2;
                }
                else break;
            }
        }
        if (maxLeft == -1 && maxRight == -1) return s.substr(0, 1);
        strWithDelim = strWithDelim.substr(maxLeft, maxRight - maxLeft + 1);
        string out = remove(strWithDelim, '*');
        return out;
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}
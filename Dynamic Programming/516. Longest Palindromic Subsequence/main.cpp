#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int strLen = s.length();
        vector<vector<int>> dp(strLen, vector<int>(strLen, 0));
        for (int i = 0; i < strLen; i++) dp[i][i] = 1;
        for (int len = 1; len < strLen; len++) {
            for (int i = 0; i < strLen - len; i++) {
                int j = i + len;
                if (s[i] == s[j]) dp[i][j] = 2 + dp[i+1][j-1];
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][strLen-1];
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}
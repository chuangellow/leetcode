#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
            if (i+1 < len && s[i] == s[i+1]) dp[i][i+1] = 2;
        }
        int width = 2;
        int left = 0, right = left + width;
        while (right < len) {
            while (right < len) {
                dp[left][right] = (dp[left+1][right-1] != 0 && s[left] == s[right])? dp[left+1][right-1] + 2: 0;
                left++;
                right++;
            }
            width++;
            left = 0, right = left + width;
        }
        int maxLen = -1;
        int maxLeft = -1, maxRight = -1;
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    maxLeft = i, maxRight = j;
                }
            }
        }
        return s.substr(maxLeft, maxRight-maxLeft+1);
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}
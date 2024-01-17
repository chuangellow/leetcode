#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 1) return s.substr(0, 1);
        if (len == 2) return (s[0] == s[1])? s.substr(0, 2): s.substr(0, 1);
        int tableLen = (len - 2) * 2 - 1;
        vector<int> dp(tableLen, 0);
        int maxLen = -1;
        int maxLeft = -1, maxRight = -1;
        if (s[0] == s[1]) {
            maxLen = 2;
            maxLeft = 0, maxRight = 1;
        }
        if (s[len-2] == s[len-1]) {
            maxLen = 2;
            maxLeft = len-2, maxRight = len-1;
        }
        for (int i = 0; i < tableLen; i++) {
            int index = (i / 2) + 1;
            if (i % 2 == 0) {
                dp[i] = 1;
                if (dp[i] > maxLen) {
                    maxLen = dp[i]; 
                    maxLeft = index; 
                    maxRight = index;
                }
            }
            if (i % 2 == 1 && s[index] == s[index + 1]) {
                dp[i] = 2;
                if (dp[i] > maxLen) {
                    maxLen = dp[i]; 
                    maxLeft = index; 
                    maxRight = index+1;
                }
            }
        }
        int width = 2;
        int left = 0, right = left + width;
        while (right < len) {
            while (right < len) {
                int index = left + right - 2; 
                dp[index] = (dp[index] != 0 && s[left] == s[right])? dp[index] + 2: 0;
                if (dp[index] > maxLen) {
                    maxLen = dp[index];
                    maxLeft = left, maxRight = right;
                }
                left++;
                right++;
            }
            width++;
            left = 0, right = left + width;
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
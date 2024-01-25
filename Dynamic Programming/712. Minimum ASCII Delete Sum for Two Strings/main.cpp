#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        for (int i = 1; i <= len1; i++) dp[i][0] = dp[i-1][0] + int(s1[i-1]);
        for (int j = 1; j <= len2; j++) dp[0][j] = dp[0][j-1] + int(s2[j-1]);
        if (len1 == 0) return dp[0][len2];
        if (len2 == 0) return dp[len1][0];
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j] + int(s1[i-1]), dp[i][j-1] + int(s2[j-1]));
            }
        }
        return dp[len1][len2];
    }
};

int main(void) {
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol;
    cout << sol.minimumDeleteSum(s1, s2) << endl;
    return 0;
}
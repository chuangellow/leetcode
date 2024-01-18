#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int strLen = s.length();
        vector<vector<bool>> dp(strLen, vector<bool>(strLen, false));
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        for (int i = 0; i < strLen; i++) {
            if (dict.find(s.substr(i, 1)) != dict.end()) {
                dp[i][i] = true;
            }
        }
        for (int len = 2; len <= strLen; len++) {
            for (int i = 0; i <= strLen - len; i++) {
                int j = i + len - 1;
                if (dict.find(s.substr(i, len)) != dict.end()) {
                    dp[i][j] = true;
                } else {
                    for (int k = i; k < j; k++) {
                        if (dp[i][k] && dp[k+1][j]) {
                            dp[i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][strLen-1];
    }
};

int main(void) {
    string s;
    cin >> s;
    int dictSize;
    cin >> dictSize;
    vector<string> wordDict(dictSize);
    for (int i = 0; i < dictSize; i++) {
        cin >> wordDict[i];
    }
    Solution sol;
    cout << ((sol.wordBreak(s, wordDict))? "true": "false") << endl;
    return 0;
}
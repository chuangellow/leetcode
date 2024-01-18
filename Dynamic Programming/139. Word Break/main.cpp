#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int strLen = s.length();
        int dictSize = wordDict.size();
        vector<bool> dp(strLen, false);
        for (int i = 0; i < strLen; i++) {
            for (int j = 0; j < dictSize; j++) {
                int wordLen = wordDict[j].length();
                if (i < wordLen - 1) continue;
                if (i == wordLen - 1 || dp[i - wordLen]) {
                    if (s.substr(i - wordLen + 1, wordLen) == wordDict[j]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[strLen - 1];
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
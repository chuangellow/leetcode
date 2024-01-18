#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int strLen = s.length();
        vector<bool> dp(strLen, false);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        for (int i = 0; i < strLen; i++) {
            if (dict.find(s.substr(0, i+1)) != dict.end()) dp[i] = true; 
            else {
                for (int k = 0; k < i; k++) {
                    if (dp[k] && dict.find(s.substr(k+1, i-k)) != dict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[strLen-1];
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
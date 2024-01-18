#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool findInDict(int left, int right, string s, vector<string>& wordDict, int dictSize) {
        for (int i = 0; i < dictSize; i++) {
            if (s.substr(left, right-left+1).compare(wordDict[i]) == 0) return true;
        }
        return false;
    }
    bool solve(int start, string s, vector<string>& wordDict, int strLen, int dictSize) {
        if (start == strLen) return true;
        for (int end = start; end < strLen; end++) {
            if (findInDict(start, end, s, wordDict, dictSize) && solve(end + 1, s, wordDict, strLen, dictSize)) {
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int strLen = s.length();
        int dictSize = wordDict.size();
        return solve(0, s, wordDict, strLen, dictSize);
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
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
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
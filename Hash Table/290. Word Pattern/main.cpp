#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> splitStrs;
        int n = s.length();
        string splitStr =  "";
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                splitStrs.push_back(splitStr);
                splitStr = "";
            }
            else {
                splitStr.push_back(s[i]);
            }
        }
        if (splitStr != "") {
            splitStrs.push_back(splitStr);
        }
        unordered_map<char, string> c2s;
        unordered_map<string, char> s2c;
        n = splitStrs.size();
        int m = pattern.size();
        if (n != m) return false;
        for (int i = 0; i < m; i++) {
            if (c2s.count(pattern[i]) == 0) {
                if (s2c.count(splitStrs[i]) != 0) return false;
                c2s[pattern[i]] = splitStrs[i];
                s2c[splitStrs[i]] = pattern[i];
            }
            else {
                if (c2s[pattern[i]].compare(splitStrs[i]) != 0) {
                    return false;
                }
                if (s2c[splitStrs[i]] != pattern[i]) return false;
            }
        }
        return true;
    }
};

int main(void) {
    string pattern, s;
    cin >> pattern >> s;
    Solution sol;
    cout << sol.wordPattern(pattern, s) << endl;
    return 0;
}
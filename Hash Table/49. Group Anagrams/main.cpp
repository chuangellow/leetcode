#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkAnagrams(string s1, string s2) {
        int count[26] = {0};
        for (auto c: s1) {
            count[c - 'a']++;
        }
        for (auto c: s2) {
            count[c - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<bool> selected(strs.size(), false);
        vector<vector<string>> out;
        for (int i = 0; i < strs.size(); i++) {
            if (selected[i]) continue;
            vector<string> s = {strs[i]};
            for (int j = i + 1; j < strs.size(); j++) {
                if (!selected[j] && checkAnagrams(strs[i], strs[j])) {
                    selected[j] = true;
                    s.push_back(strs[j]);
                }
            }
            out.push_back(s);
        }
        return out;
    }
};

int main(void) {
    int numStrings;
    cin >> numStrings;
    vector<string> strs(numStrings);
    for (int i = 0; i < numStrings; i++) {
        cin >> strs[i];
    }
    Solution sol;
    vector<vector<string>> out = sol.groupAnagrams(strs);
    for (int i = 0; i < out.size(); i++) {
        for (auto s: out[i]) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
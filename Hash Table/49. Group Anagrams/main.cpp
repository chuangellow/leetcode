#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>> dupStrs;
        vector<vector<string>> out;
        for (int i = 0; i < strs.size(); i++) {
            string newStr = strs[i];
            sort(newStr.begin(), newStr.end());
            dupStrs.push_back({newStr, i});
        }
        sort(dupStrs.begin(), dupStrs.end());
        int i = 0;
        while (i < dupStrs.size()) {
            vector<string> s = {strs[dupStrs[i].second]};
            int j;
            for (j = i + 1; j < dupStrs.size(); j++) {
                if (dupStrs[i].first == (dupStrs[j].first)) {
                    s.push_back(strs[dupStrs[j].second]);
                }
                else {
                    break;
                }
            }
            i = j;
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
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ptr = 0, n = strs.size();
        string result = "";
        while (true) {
            if (ptr > (int) strs[0].size() - 1) return result;
            char c = strs[0][ptr];
            for (int i = 1; i < n; i++) {
                if (ptr > (int) strs[i].size() - 1) return result;
                if (strs[i][ptr] != c) return result;
            }
            ptr++;
            result.push_back(c);
        }
        return result;
    }
};

int main(void) {
    int numStrs;
    cin >> numStrs;
    vector<string> strs(numStrs);
    for (int i = 0; i < numStrs; i++) cin >> strs[i];
    Solution sol;
    cout << sol.longestCommonPrefix(strs) << endl;
    return 0;
}
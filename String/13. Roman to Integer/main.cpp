#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> charMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        unordered_set<int> specialRule = {
            4, 9, 40, 90, 400, 900,
        };
        int len = s.length();
        int result = 0;
        int idx = 0;
        while (idx < len) {
            int val = charMap[s[idx]];
            if (idx + 1 < len) {
                int nextVal = charMap[s[idx+1]];
                int diff = nextVal - val;
                if (specialRule.find(diff) != specialRule.end()) {
                    result += diff;
                    idx += 2;
                    continue;
                }
            }
            result += val;
            idx += 1;
        }
        return result;
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.romanToInt(s) << endl;
    return 0;
}
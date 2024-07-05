#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len <= 1) return len;
        unordered_map<char, int> table;
        int left = 0, right = 1, currentLen = 1, maxLen = currentLen;
        table[s[left]]++;
        while (left < len && right < len) {
            while (right < len && table.count(s[right]) == 0 || table[s[right]] == 0) {
                currentLen += 1;
                table[s[right]]++;
                right++;
            }
            maxLen = max(maxLen, currentLen);
            if (right >= len) return maxLen;
            table[s[right]]++;
            currentLen++;
            while (left < len && table[s[right]] > 1) {
                table[s[left]]--;
                currentLen--;
                left++;
            }
        }
        maxLen = max(maxLen, currentLen);
        return maxLen;
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
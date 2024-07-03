#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> calculatePrefixFunction(string s) {
        int len = s.length();
        vector<int> prefixFunction(len, 0);
        int i = 1, j = 0;
        while (i < len) {
            if (s[i] == s[j]) {
                prefixFunction[i] = ++j;
                i++;
            }
            else {
                if (j != 0) {
                    j = prefixFunction[j - 1];
                }
                else {
                    i++;
                }
            }
        }
        return prefixFunction;
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> prefixFunction = calculatePrefixFunction(needle);
        int i = 0, j = 0;
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                if (j != 0) {
                    j = prefixFunction[j - 1];
                }
                else {
                    i++;
                }
            }
            if (j == m) return i - m;
        }
        return -1;
    }
};

int main(void) {
    string haystack, needle;
    cin >> haystack >> needle;
    Solution sol;
    cout << sol.strStr(haystack, needle) << endl;
    return 0;
}
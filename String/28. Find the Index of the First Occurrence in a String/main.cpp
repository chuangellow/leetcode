#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int i = 0, j = 0;
        for (int i = 0; i <= n - m; i++) {
            bool isSame = true;
            for (int j = 0; j < m; j++) {
                if (haystack[i+j] != needle[j]) {
                    isSame = false;
                    break;
                }
            }
            if (isSame) return i;
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
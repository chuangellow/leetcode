#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int currentLen = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                continue;
            }
            else {
                if (i > 0 && s[i-1] == ' ') currentLen = 0;
                currentLen += 1;
            }
        }
        return currentLen;
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.lengthOfLastWord(s) << endl;
    return 0;
}
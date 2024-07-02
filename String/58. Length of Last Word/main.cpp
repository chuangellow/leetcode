#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int lastWordLen = 0;
        int currentLen = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                if (currentLen != 0) lastWordLen = currentLen;
                currentLen = 0;
                continue;
            }
            else {
                currentLen += 1;
            }
        }
        if (currentLen != 0) lastWordLen = currentLen;
        return lastWordLen;
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.lengthOfLastWord(s) << endl;
    return 0;
}
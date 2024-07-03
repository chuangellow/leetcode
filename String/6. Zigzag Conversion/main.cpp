#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if (numRows == 1) return s;
        string result;
        int nextBlockDist = 2 * (numRows - 1);
        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows-1) {
                int pos = i;
                while (pos < len) {
                    result.push_back(s[pos]);
                    pos += nextBlockDist;
                }
            }
            else {
                int pos = i;
                while (pos < len) {
                    result.push_back(s[pos]);
                    int nextCharDist = (numRows - 1 - i) * 2;
                    if (pos + nextCharDist < len) result.push_back(s[pos + nextCharDist]);
                    pos += nextBlockDist;
                }
            }
        }
        return result;
    }
};

int main(void) {
    string s;
    cin >> s;
    int numRows;
    cin >> numRows;
    Solution sol;
    cout << sol.convert(s, numRows) << endl;
    return 0;
}
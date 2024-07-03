#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if (numRows == 1) return s;
        vector<vector<char>> temp(numRows, vector<char>(len, '\0'));
        int i = 0, j = 0, count = 0;
        int limit = numRows-1;
        while (count < len) {
            if (i + j < limit) {
                temp[i][j] = s[count];
                i++;
                count++;
            }
            else {
                temp[i][j] = s[count];
                if (i != 0) {
                    i--;
                    j++;
                }
                else {
                    limit += (numRows-1);
                    i++;
                }
                count++;
            }
        }
        string result;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < len; j++) {
                if (temp[i][j] != '\0') {
                    result.push_back(temp[i][j]);
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
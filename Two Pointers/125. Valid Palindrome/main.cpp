#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length(), cleanLen = 0;
        string cleanStr;
        for (int i = 0; i < len; i++) {
            if (isdigit(s[i])) {
                cleanStr.push_back(s[i]);
                cleanLen++;
            }
            if (isalpha(s[i])) {
                cleanStr.push_back(tolower(s[i]));
                cleanLen++;
            }
        }
        int left = 0, right = cleanLen - 1;
        while (left <= right) {
            if (cleanStr[left] != cleanStr[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.isPalindrome(s) << endl;
    return 0;
}
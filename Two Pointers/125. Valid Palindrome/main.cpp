#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int left = 0, right = len - 1;
        while (left <= right) {
            while (left <= right && !isalnum(s[left])) left++;
            while (right >= left && !isalnum(s[right])) right--;
            if (left > right) return true;
            if (tolower(s[left]) != tolower(s[right])) {
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
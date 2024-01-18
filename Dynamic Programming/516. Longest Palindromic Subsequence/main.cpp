#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(vector<bool>& mask, string s, int len) {
        int left = 0, right = len-1;
        while (!mask[left]) left++;
        while (!mask[right]) right--;
        while (left <= right) {
            if (!mask[left]) left++;
            if (!mask[right]) right--;
            if (s[left] == s[right]) {
                left++;
                right--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    void solve(int pos, int* maxSize, vector<bool>& mask, string s, int len) {
        if (pos == len) {
            if (isPalindrome(mask, s, len)) {
                int currentSize = 0;
                for (int i = 0; i < len; i++) {
                    currentSize += (mask[i]);
                }
                *maxSize = max(*maxSize, currentSize);
            }
            return;
        }
        mask[pos] = false;
        solve(pos+1, maxSize, mask, s, len);
        mask[pos] = true;
        solve(pos+1, maxSize, mask, s, len);
        return;
    }
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<bool> mask(len, true);
        int maxSize = -1;
        solve(0, &maxSize, mask, s, len);
        return maxSize;
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}
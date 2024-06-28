#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int table[26] = {0};
        int left = 0, right = 0;
        int count = 0;
        while (right < s.size()) {
            while (table[s[right] - 'a'] != 0) {
                table[s[left] - 'a'] -= 1;
                left += 1;
            }
            table[s[right] - 'a'] += 1;
            count += (right - left + 1);
            right += 1;
        }
        return count;
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.numberOfSpecialSubstrings(s) << endl;
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        int letters[26] = {0};
        for (int i = 0; i < size; i++) {
            letters[s[i]-'a']++;
        }
        for (int i = 0; i < size; i++) {
            if (letters[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.firstUniqChar(s) << endl;
    return 0;
}
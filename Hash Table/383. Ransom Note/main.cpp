#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size(), m = magazine.size();
        if (m < n) return false;
        vector<int> table(26, 0);
        for (int i = 0; i < m; i++) {
            table[magazine[i] - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            if (table[ransomNote[i] - 'a'] == 0) return false;
            table[ransomNote[i] - 'a']--;
        }
        return true;
    }
};

int main(void) {
    string ransomNote, magazine;
    cin >> ransomNote >> magazine;
    Solution sol;
    cout << sol.canConstruct(ransomNote, magazine) << endl;
}
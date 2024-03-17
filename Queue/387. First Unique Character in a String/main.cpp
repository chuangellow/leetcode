#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashTable;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            hashTable[s[i]]++;
        }
        for (int i = 0; i < size; i++) {
            if (hashTable[s[i]] == 1) return i;
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
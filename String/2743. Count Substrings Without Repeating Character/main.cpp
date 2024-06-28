#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        unordered_map<char, int> map;
        int left = 0, right = 0;
        int count = 0;
        while (right < s.size()) {
            while (map.count(s[right]) != 0) {
                map[s[left]] -= 1;
                if (map[s[left]] == 0) {
                    map.erase(s[left]);
                }
                left += 1;
            }
            if (map.count(s[right]) != 0) map[s[right]] += 1;
            else map[s[right]] = 1;
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
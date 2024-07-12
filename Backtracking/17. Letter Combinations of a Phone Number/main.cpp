#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void produce(int pos, int n, string temp, vector<vector<char>>& mapping, string digits, vector<string>& result) {
        if (pos == n) {
            result.push_back(temp);
            return;
        }
        for (auto c: mapping[digits[pos]-'2']) {
            produce(pos+1, n, temp+c, mapping, digits, result);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<vector<char>> mapping(8);
        char c = 'a';
        for (int i = 0; i < 8; i++) {
            int numChar = (i == 5 || i == 7)? 4: 3;
            for (int j = 0; j < numChar; j++) {
                mapping[i].push_back(c+j);
            }
            c += numChar;
        }
        vector<string> result;
        produce(0, digits.size(), "", mapping, digits, result);
        return result;
    }
};

int main(void) {
    string digits;
    cin >> digits;
    Solution sol;
    vector<string> result = sol.letterCombinations(digits);
    for (auto ret: result) {
        cout << ret << " ";
    }
    return 0;
}
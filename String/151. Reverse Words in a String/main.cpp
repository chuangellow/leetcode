#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> words;
        string word = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (word != "") {
                    words.push_back(word);
                    word = "";
                }
                continue;
            }
            word.push_back(s[i]);
        }
        if (word != "") words.push_back(word);
        int numWords = words.size();
        string result = "";
        for (int i = numWords - 1; i >= 0; i--) {
            result.append(words[i]);
            if (i != 0) {
                result.push_back(' ');
            }
        }
        return result;
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.reverseWords(s) << endl;
    return 0;
}
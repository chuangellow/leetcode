#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int checkBrackets(char c, char brackets[6]) {
        for (int i = 0; i < 6; i++) {
            if (brackets[i] == c) return i;
        }
        return -1;
    }
    bool isValid(string s) {
        char brackets[6] = {'(', '{', '[', ')', '}', ']'};
        std::stack<char> mystack;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            int ret = checkBrackets(s.at(i), brackets);
            if (ret == -1) continue;
            if (ret < 3) {
                mystack.push(s.at(i));
            }
            else {
                if (mystack.empty()) return false;
                char c = mystack.top();
                mystack.pop();
                if (c != brackets[ret-3]) return false;
            }
        }
        return (mystack.empty());
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.isValid(s) << endl;
}
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int size = s.length();
        string outStr;
        stack<int> leftStack;
        stack<int> rightStack;
        for (int i = size-1; i >= 0; i--) {
            switch (s[i]) {
                case ')':
                    rightStack.push(i);
                    break;
                case '(':
                    if (rightStack.empty()) leftStack.push(i);
                    else rightStack.pop();
                    break;
                default:
                    break;
            }
        }
        for (int i = 0; i < size; i++) {
            switch (s[i]) {
                case '(':
                    if (!leftStack.empty() && i == leftStack.top()) {
                        leftStack.pop();
                        continue;
                    }
                    outStr.push_back(s[i]);
                    break;
                case ')':
                    if (!rightStack.empty() && i == rightStack.top()) {
                        rightStack.pop();
                        continue;
                    }
                    outStr.push_back(s[i]);
                    break;
                default:
                    outStr.push_back(s[i]);
                    break;
            }
        }
        return outStr;
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.minRemoveToMakeValid(s) << endl;
}
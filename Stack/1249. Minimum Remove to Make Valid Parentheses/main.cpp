#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string::size_type size = s.length();
        string outStr;
        stack<char> myStack;
        vector<int> invalidLeft;
        vector<int> invalidRight;
        for (int i = 0; i < size; i++) {
            switch (s.at(i)) {
                case ')':
                    if (myStack.empty()) invalidRight.push_back(i);
                    else myStack.pop();
                    break;
                case '(':
                    myStack.push('(');
                    break;
                default:
                    break;
            }
        }
        while (!myStack.empty()) myStack.pop();
        for (int i = size-1; i >= 0; i--) {
            switch (s.at(i)) {
                case '(':
                    if (myStack.empty()) invalidLeft.push_back(i);
                    else myStack.pop();
                    break;
                case ')':
                    myStack.push(')');
                    break;
                default:
                    break;
            }
        }
        int lsize = invalidLeft.size(), rsize = invalidRight.size();
        int lCount = lsize-1, rCount = 0;
        for (int i = 0; i < size; i++) {
            switch (s[i]) {
                case ')':
                    if (rCount < rsize && i == invalidRight[rCount]) {
                        rCount++;
                        continue;
                    }
                    outStr.push_back(')');
                    break;
                case '(':
                    if (lCount >= 0 && i == invalidLeft[lCount]) {
                        lCount--;
                        continue;
                    }
                    outStr.push_back('(');
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
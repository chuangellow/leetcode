#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        // ensure that after parsing the s, the sum of the lValueStack is the result.
        // we do the last operation until we encounter the next operation.
        size_t size = s.length();
        int rValue = 0;
        stack<int> lValueStack;
        char lastOp = '+';
        for (int i = 0; i < size; i++) {
            char c = s[i];
            if (isdigit(c)) rValue = rValue * 10 + (c - '0');
            else if (!iswspace(c)) {
                if (lastOp == '+') {
                    lValueStack.push(rValue);
                }
                else if (lastOp == '-') {
                    lValueStack.push(-rValue);
                }
                else if (lastOp == '*') {
                    int lValue = lValueStack.top();
                    lValueStack.pop();
                    lValueStack.push(lValue * rValue);
                }
                else if (lastOp == '/') {
                    int lValue = lValueStack.top();
                    lValueStack.pop();
                    lValueStack.push(lValue / rValue);
                }
                lastOp = c;
                rValue = 0;
            }
        }
        if (lastOp == '+') {
            lValueStack.push(rValue);
        }
        else if (lastOp == '-') {
            lValueStack.push(-rValue);
        }
        else if (lastOp == '*') {
            int lValue = lValueStack.top();
            lValueStack.pop();
            lValueStack.push(lValue * rValue);
        }
        else if (lastOp == '/') {
            int lValue = lValueStack.top();
            lValueStack.pop();
            lValueStack.push(lValue / rValue);
        }
        int result = 0;
        while (!lValueStack.empty()) {
            result += lValueStack.top();
            lValueStack.pop();
        }
        return result;
    }
};

int main(void) {
    string s;
    getline(cin, s);
    Solution sol;
    cout << sol.calculate(s) << endl;
    return 0;
}
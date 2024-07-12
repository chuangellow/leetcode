#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        if (n < 2) return 0;
        bool checkAB = (x > y);
        int currentScore = 0;
        stack<char> myStack;
        for (int i = 0; i < n; i++) {
            if (checkAB) {
                if (!myStack.empty() && s[i] == 'b' && myStack.top() == 'a') {
                    currentScore += x;
                    myStack.pop();
                }
                else {
                    myStack.push(s[i]);
                }
            }
            else {
                if (!myStack.empty() && s[i] == 'a' && myStack.top() == 'b') {
                    currentScore += y;
                    myStack.pop();
                }
                else {
                    myStack.push(s[i]);
                }
            }
        }
        stack<char> anotherStack;
        while (!myStack.empty()) {
            char c = myStack.top();
            myStack.pop();
            if (checkAB) {
                if (!anotherStack.empty() && c == 'b' && anotherStack.top() == 'a') {
                    currentScore += y;
                    anotherStack.pop();
                }
                else {
                    anotherStack.push(c);
                }
            }
            else {
                if (!anotherStack.empty() && c == 'a' && anotherStack.top() == 'b') {
                    currentScore += x;
                    anotherStack.pop();
                }
                else {
                    anotherStack.push(c);
                }
            }
        }
        return currentScore;
    }
};

int main(void) {
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    Solution sol;
    cout << sol.maximumGain(s, x, y) << endl;
    return 0;
}
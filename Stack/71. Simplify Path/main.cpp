#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string outputStr;
        string delim = "/";
        size_t pos;
        string token;
        stack<string> myStack;
        while ((pos = path.find(delim)) != string::npos) {
            token = path.substr(0, pos);
            path.erase(0, pos+delim.length());
            if (token.compare("") == 0) continue;
            if (token.compare(".") == 0) continue;
            if (token.compare("..") == 0) {
                if (!myStack.empty()) myStack.pop();
                continue;
            }
            myStack.push(token);
        }
        token = path.substr(0, string::npos);
        if (token.compare(".") != 0 && token.compare("") != 0) {
            if (token.compare("..") == 0) {
                if (!myStack.empty()) myStack.pop();
            }
            else {
                myStack.push(token);
            }
        }
        stack<string> outStack;
        while (!myStack.empty()) {
            outStack.push(myStack.top());
            myStack.pop();
        }
        while (!outStack.empty()) {
            outputStr.push_back('/');
            outputStr.append(outStack.top());
            outStack.pop();
        }
        if (outputStr.empty()) outputStr.push_back('/');
        return outputStr;
    }
};

int main(void) {
    string path;
    cin >> path;
    Solution sol;
    cout << sol.simplifyPath(path) << endl;
}
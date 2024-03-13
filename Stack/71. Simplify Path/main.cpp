#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int traverse(string path, char target, int start, int size) {
        int idx = start+1;
        int len = 1;
        for (; idx < size; idx++) {
            if (path.at(idx) != target) return len;
            len++;
        }
        return len;
    }
    string simplifyPath(string path) {
        string outPath;
        stack<char> myStack;
        myStack.push(path.at(0));
        int size = path.length();
        int index = 1;
        int len;
        int count;
        while (index < size) {
            switch (path.at(index)) {
                case '/':
                    len = traverse(path, '/', index, size);
                    if (myStack.top() == '/') {
                        index = index + len;
                        continue;
                    }
                    myStack.push('/');
                    index = index + len;
                    break;
                case '.':
                    len = traverse(path, '.', index, size);
                    if (len <= 2) {
                        if (path.at(index-1) != '/' || index + len < size && path.at(index + len) != '/') {
                            for (int i = 0; i < len; i++) myStack.push('.');
                            index = index + len;
                            break;
                        }
                        count = 0;
                        while (!myStack.empty() && count < len) {
                            if (myStack.top() == '/') count++;
                            myStack.pop();
                        }
                        if (myStack.empty()) myStack.push('/');
                    }
                    else {
                        for (int i = 0; i < len; i++) myStack.push('.');
                    }
                    index = index + len;
                    break;
                default:
                    myStack.push(path.at(index));
                    index++;
                    break;
            }
        }
        if (myStack.top() == '/') myStack.pop();
        if (myStack.empty()) myStack.push('/');
        stack<char> outStack;
        while (!myStack.empty()) {
            outStack.push(myStack.top());
            myStack.pop();
        }
        while (!outStack.empty()) {
            outPath.push_back(outStack.top());
            outStack.pop();
        }
        return outPath;
    }
};

int main(void) {
    string path;
    cin >> path;
    Solution sol;
    cout << sol.simplifyPath(path) << endl;
}
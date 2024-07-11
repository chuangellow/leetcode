#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        queue<char> q;
        for (char c: s) {
            if (c != ')') {
                st.push(c);
            }
            else {
                while (!st.empty() && st.top() != '(') {
                    q.push(st.top());
                    st.pop();
                }
                st.pop(); // remove '('
                while (!q.empty()) {
                    st.push(q.front());
                    q.pop();
                }
            }
        }
        int n = st.size();
        string result(n, '\0');
        for (int i = n-1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.reverseParentheses(s) << endl;
}
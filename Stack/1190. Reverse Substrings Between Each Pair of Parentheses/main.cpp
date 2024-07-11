#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.length();
        int count = 0;
        vector<int> tunnels(n, -1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
                count++;
            }
            else if (s[i] == ')') {
                tunnels[st.top()] = i;
                tunnels[i] = st.top();
                st.pop();
                count++;
            }
        }
        string result;
        int currentIdx = 0, direction = 1;
        int currentLen = 0;
        while (currentIdx >= 0 && currentIdx < n && currentLen < (n - count)) {
            if (tunnels[currentIdx] != -1) {
                currentIdx = tunnels[currentIdx];
                direction *= -1;
            }
            else {
                result.push_back(s[currentIdx]);
                currentLen++;
            }
            currentIdx += direction;
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
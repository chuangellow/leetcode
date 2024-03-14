#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int strToInt(string s) {
        int val;
        stringstream ss;
        ss << s;
        ss >> val;
        return val;
    }
    string intToStr(int val) {
        string out;
        stringstream ss;
        ss << val;
        ss >> out;
        return out;
    }
    int calculate(string s) {
        return 0;
    }
};

int main(void) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.calculate(s) << endl;
    return 0;
}
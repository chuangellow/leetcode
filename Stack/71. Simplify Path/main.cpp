#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> components;
        stringstream ss(path);
        string item;
        while (getline(ss, item, '/')) {
            if (item == "" || item == ".") continue;
            if (item == ".." && !components.empty()) components.pop_back();
            else if (item != "..") components.push_back(item);
        }
        string result = "";
        for (const string& component: components) {
            result += "/" + component;
        }
        return result.empty() ? "/": result;
    }
};

int main(void) {
    string path;
    cin >> path;
    Solution sol;
    cout << sol.simplifyPath(path) << endl;
}
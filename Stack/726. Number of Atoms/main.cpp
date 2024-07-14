#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    pair<int, int> str2int(string formula, int start) {
        int idx = start;
        int result = 0;
        while (start < formula.size() && isdigit(formula[idx])) {
            result = result * 10 + (formula[idx] - '0');
            idx++;
        }
        return {result, idx};
    }
    bool is_digits(const std::string &str)
    {
        return std::all_of(str.begin(), str.end(), ::isdigit);
    }
    string countOfAtoms(string formula) {
        int n = formula.length();
        // 1. find all of the elements exist in the formula and produce the string with 1 count.
        string temp;
        unordered_map<string, int> counts;
        int i = 0;
        while (i < n) {
            string s;
            char c = formula[i];
            if (isalpha(c) && isupper(c)) {
                temp.push_back(c);
                s.push_back(c);
                if (i + 1 < n && isalpha(formula[i+1]) && islower(formula[i+1])) {
                    temp.push_back(formula[i+1]);
                    s.push_back(formula[i+1]);
                    i++;
                }
                if (i + 1 == n || i + 1 < n && !isdigit(formula[i+1])) {
                    temp.push_back('1');
                }
            }
            else {
                temp.push_back(c);
            }
            if (!s.empty()) counts[s] = 0;
            i++;
        }
        // 2. remove all of the parentheses.
        cout << temp << endl;
        stack<string> myStack;
        int newN = temp.size();
        i = 0;
        while (i < newN) {
            if (temp[i] == ')') {
                pair<int, int> result = str2int(temp, i+1);
                if (result.second == i+1) result.first = 1;
                stack<string> anotherStack;
                while (myStack.top() != "(") {
                    if (is_digits(myStack.top())) {
                        int topVal = str2int(myStack.top(), 0).first;
                        topVal *= result.first;
                        myStack.pop();
                        anotherStack.push(to_string(topVal));
                    }
                    else {
                        anotherStack.push(myStack.top());
                        myStack.pop();
                    }
                }
                myStack.pop(); // remove '('
                while (!anotherStack.empty()) {
                    myStack.push(anotherStack.top());
                    anotherStack.pop();
                }
                i = result.second;
            }
            else {
                if (isdigit(temp[i])) {
                    pair<int, int> result = str2int(temp, i);
                    myStack.push(to_string(result.first));
                    i = result.second;
                }
                else if (temp[i] == '(') {
                    myStack.push("(");
                    i++;
                }
                else {
                    string s;
                    s.push_back(temp[i]);
                    if (i + 1 < newN && islower(temp[i + 1])) {
                        s.push_back(temp[i+1]);
                        i++;
                    }
                    i++;
                    myStack.push(s);
                }
            }
        }
        while (!myStack.empty()) {
            int val = str2int(myStack.top(), 0).first;
            myStack.pop();
            string element = myStack.top();
            myStack.pop();
            counts[element] += val;
        }
        vector<pair<string, int>> sorted_counts(counts.begin(), counts.end());
        sort(sorted_counts.begin(), sorted_counts.end());
        string output;
        for (auto element: sorted_counts) {
            output = output + element.first;
            if (element.second != 1) {
                output = output + to_string(element.second);
            }
        }
        return output;
    }
};

int main(void) {
    string formula;
    cin >> formula;
    Solution sol;
    cout << sol.countOfAtoms(formula) << endl;
    return 0;
}
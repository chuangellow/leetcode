#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int size = s.length();
        string outStr;
        int count = 0;
        vector<int> rightIdx;
        vector<int> leftIdx;
        for (int i = 0; i < size; i++) {
            switch (s[i]) {
                case '(':
                    leftIdx.push_back(i);
                    count++;
                    break;
                case ')':
                    if (count != 0) {
                        rightIdx.push_back(i);
                        count--;
                    }
                    break;
                default:
                    break;
            }
        }
        for (int i = 0; i < count; i++) leftIdx.pop_back();
        int left = 0, right = 0;
        int leftSize = leftIdx.size(), rightSize = rightIdx.size();
        for (int i = 0; i < size; i++) {
            switch (s[i]) {
                case '(':
                    if (left < leftSize && i == leftIdx[left]) {
                        outStr.push_back(s[i]);
                        left++;
                    }
                    break;
                case ')':
                    if (right < rightSize && i == rightIdx[right]) {
                        outStr.push_back(s[i]);
                        right++;
                    }
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
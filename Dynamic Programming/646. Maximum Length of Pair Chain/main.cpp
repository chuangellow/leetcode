#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int prevRight = pairs[0][1];
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (pairs[i][0] > prevRight) {
                len++;
                prevRight = pairs[i][1];
            }
        }
        return len;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> pairs(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> pairs[i][0] >> pairs[i][1];
    }
    Solution sol;
    cout << sol.findLongestChain(pairs) << endl;
}
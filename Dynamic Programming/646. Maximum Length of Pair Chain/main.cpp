#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int linearSearch(vector<int>& secondNums, int targetLeft, int targetRight, int n) {
        for (int i = 0; i < n; i++) {
            if (secondNums[i] >= targetLeft && secondNums[i] > targetRight) return i;
        }
        return -1;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<int> secondNums = {pairs[0][1]};
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (pairs[i][0] > secondNums[len-1]) {
                secondNums.push_back(pairs[i][1]);
                len++;
            }
            else {
                int idx = linearSearch(secondNums, pairs[i][0], pairs[i][1], len);
                if (idx != -1) secondNums[idx] = pairs[i][1];
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
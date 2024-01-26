#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int n = pairs.size();
        vector<int> dp(n, 1);
        int finalMaxValue = 1;
        for (int i = 1; i < n; i++) {
            int maxValue = -1;
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] <= pairs[j][1]) continue;
                maxValue = max(maxValue, dp[j]);
            }
            dp[i] = maxValue + 1;
            finalMaxValue = max(finalMaxValue, dp[i]);
        }
        return finalMaxValue;
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
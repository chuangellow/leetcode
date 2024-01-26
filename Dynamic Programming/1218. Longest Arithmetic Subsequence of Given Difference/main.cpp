#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<int> dp(n, 1);
        int finalMaxValue = 1;
        for (int i = 1; i < n; i++) {
            int maxValue = 0;
            for (int j = 0; j < i; j++) {
                if (arr[i] - arr[j] != difference) continue;
                maxValue = max(dp[j], maxValue);
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int difference;
    cin >> difference;
    Solution sol;
    cout << sol.longestSubsequence(arr, difference) << endl;
    return 0;
}
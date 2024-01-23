#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1Len = word1.length();
        int word2Len = word2.length();
        vector<vector<int>> dp(word1Len+1, vector<int>(word2Len+1, 0));

        for (int i = 0; i <= word1Len; i++) dp[i][0] = i;
        for (int i = 0; i <= word2Len; i++) dp[0][i] = i;

        for (int i = 1; i <= word1Len; i++) {
            for (int j = 1; j <= word2Len; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                }
            }
        }
        return dp[word1Len][word2Len];
    }
};

int main(void) {
    string word1, word2;
    cin >> word1 >> word2;
    Solution sol;
    cout << sol.minDistance(word1, word2) << endl;
    return 0;
}
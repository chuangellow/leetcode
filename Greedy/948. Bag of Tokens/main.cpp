#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(int score, int *maxScore, int power, vector<int>& tokens, int size) {
        if (tokens[0] > power) {
            *maxScore = 0; 
            return;
        }
        int left = 0, right = size - 1;
        bool flag = true;
        while (left <= right && flag) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                score++;
                left++;
                *maxScore = max(*maxScore, score);
            }
            else {
                if (score >= 1) {
                    *maxScore = max(*maxScore, score);
                    score--;
                    power += tokens.at(right);
                    right--;
                }
                else flag = false;
            }
        }
    }
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int size = tokens.size();
        if (size == 0) return 0;
        int maxScore = INT32_MIN;
        sort(tokens.begin(), tokens.end());
        solve(0, &maxScore, power, tokens, size);
        return maxScore;
    }
};

int main(void) {
    int numTokens, power;
    cin >> numTokens >> power;
    vector<int> tokens(numTokens, 0);
    for (int i = 0; i < numTokens; i++) cin >> tokens[i];
    Solution sol;
    cout << sol.bagOfTokensScore(tokens, power) << endl;
}
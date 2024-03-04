#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
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
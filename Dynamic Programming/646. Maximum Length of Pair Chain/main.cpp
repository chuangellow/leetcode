#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void getLenOfLongestChain(int len, int* maxLen, vector<int>& chain, vector<bool>& selected, vector<vector<int>>& pairs, int n) {
        bool flag = false;
        for (int i = 0; i < n; i++) {
           if (selected[i]) continue;
           if (pairs[i][0] > pairs[chain[len-1]][1]) {
            flag = true;
            chain.push_back(i);
            selected[i] = true;
            getLenOfLongestChain(len+1, maxLen, chain, selected, pairs, n);
            selected[i] = false;
            chain.pop_back();
           }
        }
        if (!flag) *maxLen = max(*maxLen, len);
        return;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<bool> selected(n, false);
        vector<int> chain;
        int maxLen = -1;
        for (int i = 0; i < n; i++) {
            chain.push_back(i);
            selected[i] = true;
            getLenOfLongestChain(1, &maxLen, chain, selected, pairs, n);
            selected[i] = false;
            chain.pop_back();
        }
        return maxLen;
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
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
    }
};

int main(void) {
    int n;
    vector<vector<int>> pairs(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> pairs[i][0] >> pairs[i][1];
    }
    Solution sol;
    cout << sol.findLongestChain(pairs) << endl;
}
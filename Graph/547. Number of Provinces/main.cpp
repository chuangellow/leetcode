#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
    }
};

int main(void) {
    int n;
    vector<vector<int>> isConnected(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }
    Solution sol;
    cout << sol.findCircleNum(isConnected) << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    Solution sol;
    cout << sol.minFallingPathSum(matrix) << endl;
    return 0;
}
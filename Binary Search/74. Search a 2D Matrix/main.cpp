#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;
    int target;
    cin >> target;
    vector<vector<int> > matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix.at(i).at(j);
        }
    }
    Solution sol;
    cout << sol.searchMatrix(matrix, target) << endl;
    return 0;
}
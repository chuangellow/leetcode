#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int rowIdx = n - 1, colIdx = m - 1;
        while (rowIdx >= 0) {
            int num = grid.at(rowIdx).at(colIdx);
            if (num < 0) count++;
            if (num > 0 || colIdx == 0) {
                colIdx = m - 1;
                rowIdx--;
            }
            else {
                colIdx--;
            }
        }
        return count;
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid.at(i).at(j);
        }
    }
    Solution sol;
    cout << sol.countNegatives(grid) << endl;
    return 0;
}
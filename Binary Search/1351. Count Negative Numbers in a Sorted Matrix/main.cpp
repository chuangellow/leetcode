#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getRowNegatives(vector<vector<int>>& grid, int rowIdx, int cols) {
        int left = 0, right = cols - 1;
        while (left < right) {
            int mid = (unsigned int) (left + right) >> 1;
            int midNum = grid.at(rowIdx).at(mid);
            if (midNum >= 0) left = mid + 1;
            else right = mid;
        }
        return (grid.at(rowIdx).at(left) < 0)? cols - left: 0;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int lastNegativeIdx = m - 1;
        for (int rowIdx = 0; rowIdx < n; rowIdx++) {
            int negColIdx = lastNegativeIdx;
            count += (m - (negColIdx + 1));
            count += getRowNegatives(grid, rowIdx, negColIdx + 1);
            lastNegativeIdx = negColIdx;
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
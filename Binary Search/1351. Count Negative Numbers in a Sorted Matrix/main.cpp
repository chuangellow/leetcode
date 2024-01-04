#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int lastNegativeIdx = m - 1;
        for (int rowIdx = 0; rowIdx < n; rowIdx++) {
            int negColIdx = lastNegativeIdx;
            count += (m - (negColIdx + 1));
            while (negColIdx >= 0 && grid.at(rowIdx).at(negColIdx) < 0) {
                count++;
                negColIdx--;
            }
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
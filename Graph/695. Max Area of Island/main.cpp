#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = 0;
                    stack<pair<int, int>> s;
                    s.push(pair(i, j));
                    visited[i][j] = true;
                    while (!s.empty()) {
                        pair<int, int> pos = s.top();
                        s.pop();
                        area += 1;
                        for (int k = 0; k < 4; k++) {
                            int x = pos.first + dx[k];
                            int y = pos.second + dy[k];
                            if (x >= m || x < 0 || y >= n || y < 0) continue;
                            if (grid[x][y] == 1 && !visited[x][y]) {
                                s.push(pair(x, y));
                                visited[x][y] = true;
                            }
                        }
                    }
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    Solution sol;
    cout << sol.maxAreaOfIsland(grid) << endl;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void bfs(pair<int, int> source, vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push(source);
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        while (!q.empty()) {
            pair<int, int> pos = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newX = pos.first + dx[i];
                int newY = pos.second + dy[i];
                if (newX < 0 || newX >= m || newY < 0 || newY >= n) continue;
                if (grid[newX][newY] == '1') {
                    q.push({newX, newY});
                    grid[newX][newY] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    bfs({i, j}, grid);
                }
            }
        }
        return count;
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    Solution sol;
    cout << sol.numIslands(grid) << endl;
    return 0;
}
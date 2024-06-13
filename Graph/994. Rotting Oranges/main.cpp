#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void printGrid(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> distance(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) distance[i][j] = INT32_MAX;
            }
        }
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2 && distance[i][j] == INT32_MAX) {
                    distance[i][j] = 0;
                    stack<pair<pair<int, int>, int>> s;
                    s.push({{i, j}, 0});
                    while (!s.empty()) {
                        pair<int, int> pos = s.top().first;
                        int d = s.top().second;
                        s.pop();
                        for (int k = 0; k < 4; k++) {
                            int x = pos.first + dx[k];
                            int y = pos.second + dy[k];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                                if (d+1 < distance[x][y]) {
                                    distance[x][y] = d + 1;
                                    s.push({{x, y}, d + 1});
                                }
                            }
                        }
                    }
                }
            }
        }
        int maxDistance = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && distance[i][j] == INT32_MAX) return -1;
                maxDistance = max(distance[i][j], maxDistance);
            }
        }
        return maxDistance;
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    Solution sol;
    cout << sol.orangesRotting(grid) << endl;
    return 0;
}
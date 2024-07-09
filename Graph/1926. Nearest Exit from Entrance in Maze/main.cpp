#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBoundary(pair<int, int>& pos, int m, int n) {
        return pos.first == 0 || pos.first == m-1 || pos.second == 0 || pos.second == n-1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<pair<int, int>, int>> q; // pos[0], pos[1], distance
        q.push({{entrance[0], entrance[1]}, 0});
        maze[entrance[0]][entrance[1]] = '+';
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        int minDistance = INT32_MAX;
        while (!q.empty()) {
            pair<int, int> pos = q.front().first;
            int distance = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                pair<int, int> newPos = {pos.first + dx[i], pos.second + dy[i]};
                if (newPos.first < 0 || newPos.first >= m || newPos.second < 0 || newPos.second >= n) continue;
                if (maze[newPos.first][newPos.second] == '+') continue;
                if (isBoundary(newPos, m, n)) {
                    return distance + 1;
                }
                maze[newPos.first][newPos.second] = '+';
                q.push({newPos, distance+1});
            }
        }
        return -1;
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> maze(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    vector<int> entrance(2);
    cin >> entrance[0] >> entrance[1];
    Solution sol;
    cout << sol.nearestExit(maze, entrance);
    return 0;
}
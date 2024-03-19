#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dirs = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    int width, height;
    vector<int> proceedUntilWall(vector<vector<int>>& maze, vector<int>& pos, vector<int>& dir) {
        int currentX = pos[0], currentY = pos[1];
        while (currentX >= 0 && currentX < height && currentY >= 0 && currentY < width && (!maze[currentX][currentY])) {
            currentX += dir[0];
            currentY += dir[1];
        }
        if (currentX >= 0 && currentX < height && currentY >= 0 && currentY < width && (!maze[currentX][currentY])) return {currentX, currentY};
        else return {currentX - dir[0], currentY - dir[1]};
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<vector<int>> candidates;
        candidates.push(start);
        height = maze.size();
        width = maze[0].size();
        bool visited[height][width];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                visited[i][j] = false;
            }
        }
        while (!(candidates.empty())) {
            vector<int> currentPos = candidates.front();
            candidates.pop();
            if (visited[currentPos[0]][currentPos[1]]) continue;
            visited[currentPos[0]][currentPos[1]] = true;
            for (int i = 0; i < 4; i++) {
                vector<int> newPos = proceedUntilWall(maze, currentPos, dirs[i]);
                if (newPos[0] == destination[0] && newPos[1] == destination[1]) return true;
                if (newPos[0] == currentPos[0] && newPos[1] == currentPos[1]) continue;
                candidates.push(newPos);
            }
        }
        return false;
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> maze(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    vector<int> start(2, 0);
    cin >> start[0] >> start[1];
    vector<int> end(2, 0);
    cin >> end[0] >> end[1];
    Solution sol;
    cout << sol.hasPath(maze, start, end) << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int originColor = image[sr][sc];
        image[sr][sc] = color;
        visited[sr][sc] = true;
        q.push({sr, sc});
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        while (!q.empty()) {
            pair<int, int> pos = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                pair<int, int> newPos = {pos.first + dx[i], pos.second + dy[i]};
                if (newPos.first < 0 || newPos.first >= m || newPos.second < 0 || newPos.second >= n) continue;
                if (visited[newPos.first][newPos.second]) continue;
                if (image[newPos.first][newPos.second] != originColor) continue;
                image[newPos.first][newPos.second] = color;
                visited[newPos.first][newPos.second] = true;
                q.push(newPos);
            }
        }
        return image;
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> image(m, vector<int>(n));
    int sr, sc, color;
    cin >> sr >> sc >> color;
    Solution sol;
    image = sol.floodFill(image, sr, sc, color);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
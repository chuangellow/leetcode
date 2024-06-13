#include <iostream>
#include <vector>
#include <stack>

using namespace std;
#define INF 2147483647

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    stack<pair<pair<int, int>, int>> s;
                    s.push(pair(pair(i, j), 0));
                    while (!s.empty()) {
                        pair<int, int> pos = s.top().first;
                        int d = s.top().second;
                        s.pop();
                        for (int k = 0; k < 4; k++) {
                            int x = pos.first + dx[k];
                            int y = pos.second + dy[k];
                            if (x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] != -1 && rooms[x][y] != 0) {
                                if (d + 1 < rooms[x][y]) {
                                    rooms[x][y] = d + 1;
                                    s.push(pair(pair(x, y), d + 1));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> rooms(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> rooms[i][j];
        }
    }
    Solution sol;
    sol.wallsAndGates(rooms);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << rooms[i][j] << " ";
        }
        cout << endl;
    }
}
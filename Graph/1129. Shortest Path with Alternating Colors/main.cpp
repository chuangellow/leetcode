#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void bfs(int n, vector<vector<bool>> redMatrix, vector<vector<bool>> blueMatrix, vector<int>& result, bool isRedTurn) {
        queue<pair<pair<int, int>, bool>> q;
        q.push({{0, 0}, isRedTurn});
        while (!q.empty()) {
            int idx = q.front().first.first;
            int distance = q.front().first.second;
            bool turn = q.front().second;
            q.pop();
            result[idx] = min(result[idx], distance);
            if (turn) {
                for (int j = 0; j < n; j++) {
                    if (!redMatrix[idx][j]) continue;
                    redMatrix[idx][j] = false;
                    q.push({{j, distance+1}, !turn});
                }
            }
            else {
                for (int j = 0; j < n; j++) {
                    if (!blueMatrix[idx][j]) continue;
                    blueMatrix[idx][j] = false;
                    q.push({{j, distance+1}, !turn});
                }
            }
        }
        return;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<bool>> redMatrix(n, vector<bool>(n, false)), blueMatrix(n, vector<bool>(n, false));
        for (auto edge: redEdges) {
            redMatrix[edge[0]][edge[1]] = true;
        }
        for (auto edge: blueEdges) {
            blueMatrix[edge[0]][edge[1]] = true;
        }
        vector<int> result(n, INT32_MAX);
        bfs(n, redMatrix, blueMatrix, result, true);
        bfs(n, redMatrix, blueMatrix, result, false);
        for (int i = 0; i < n; i++) {
            if (result[i] == INT32_MAX) result[i] = -1;
        }
        return result;
    }
};

int main(void) {
    int n;
    cin >> n;
    int numRedEdges, numBlueEdges;
    cin >> numRedEdges >> numBlueEdges;
    vector<vector<int>> redEdges(numRedEdges, vector<int>(2));
    for (int i = 0; i < numRedEdges; i++) {
        int u, v;
        cin >> u >> v;
        redEdges[i] = {u, v};
    }
    vector<vector<int>> blueEdges(numBlueEdges, vector<int>(2));
    for (int i = 0; i < numBlueEdges; i++) {
        int u, v;
        cin >> u >> v;
        blueEdges[i] = {u, v};
    }
    Solution sol;
    vector<int> result = sol.shortestAlternatingPaths(n, redEdges, blueEdges);
    for (auto num: result) cout << num << " ";
    return 0;
}
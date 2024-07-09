#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDegrees(n, 0);
        for (auto edge: edges) {
            inDegrees[edge[1]]++;
        }
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (inDegrees[i] == 0) result.push_back(i);
        }
        return result;
    }
};

int main(void) {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    vector<vector<int>> edges(numEdges, vector<int>(2));
    for (int i = 0; i < numEdges; i++) cin >> edges[i][0] >> edges[i][1];
    Solution sol;
    vector<int> result = sol.findSmallestSetOfVertices(numNodes, edges);
    for (auto num: result) cout << num << " ";
    cout << endl;
    return 0;
}
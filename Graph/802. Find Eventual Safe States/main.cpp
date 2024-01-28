#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
    }
};

int main(void) {
    int numNodes;
    cin >> numNodes;
    vector<vector<int>> graph(numNodes);
    for (int i = 0; i < numNodes; i++) {
        int numEdges;
        cin >> numEdges;
        vector<int> edges = {};
        for (int j = 0; j < numEdges; j++) {
            int idx;
            cin >> idx;
            edges.push_back(idx);
        }
        graph[i] = edges;
    }
    Solution sol;
    vector<int> ans = sol.eventualSafeNodes(graph);
    int ansLen = ans.size();
    for (int i = 0; i < ansLen; i++) cout << ans[i] << " ";
    cout << endl;
}

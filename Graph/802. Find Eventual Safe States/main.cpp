#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        return vector<int> {};
    }
};

int main(void) {
    int numNodes;
    cin >> numNodes;
    vector<vector<int>> graph;
    for (int i = 0; i < numNodes; i++) {
        int numEdges;
        cin >> numEdges;
        for (int j = 0; j < numEdges; j++) {
            int idx;
            cin >> idx;
            vector<int> edge = {i, idx};
            cout << i << " " << idx << endl;
            graph.push_back(edge);
        }
    }
    Solution sol;
    vector<int> ans = sol.eventualSafeNodes(graph);
    int ansLen = ans.size();
    for (int i = 0; i < ansLen; i++) cout << ans[i] << " ";
    cout << endl;
}

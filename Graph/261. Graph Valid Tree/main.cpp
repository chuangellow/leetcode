#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
    }
};

int main(void) {
    int numNodes;
    cin >> numNodes;
    int numEdges;
    cin >> numEdges;
    vector<vector<int>> edges(numEdges, vector<int>(2));
    for (int i = 0; i < numEdges; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    Solution sol;
    cout << sol.validTree(numNodes, edges) << endl;
    return 0;
}
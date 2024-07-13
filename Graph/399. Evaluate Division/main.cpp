#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    double bfs(int source, int target, vector<vector<bool>>& hasEdge, vector<vector<double>>& edgeVal) {
        int n = hasEdge.size();
        vector<bool> visited(n, false);
        queue<pair<int, double>> q;
        q.push({source, 1.0});
        visited[source] = true;
        while (!q.empty()) {
            int u = q.front().first;
            double currentVal = q.front().second;
            q.pop();
            for (int v = 0; v < n; v++) {
                if (!hasEdge[u][v]) continue;
                if (visited[v]) continue;
                if (v == target) return currentVal * edgeVal[u][v];
                visited[v] = true;
                q.push({v, currentVal * edgeVal[u][v]});
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int count = 0;
        vector<string> nodes;
        unordered_map<string, int> map;
        for (auto equation: equations) {
            if (map.count(equation[0]) == 0) {
                nodes.push_back(equation[0]);
                map[equation[0]] = count;
                count++;
            }
            if (map.count(equation[1]) == 0) {
                nodes.push_back(equation[1]);
                map[equation[1]] = count;
                count++;
            }
        }
        vector<vector<bool>> hasEdge(nodes.size(), vector<bool>(nodes.size(), false));
        vector<vector<double>> edgeVal(nodes.size(), vector<double>(nodes.size(), 0));
        for (int i = 0; i < equations.size(); i++) {
            int u = map[equations[i][0]];
            int v = map[equations[i][1]];
            hasEdge[u][v] = hasEdge[v][u] = true;
            edgeVal[u][v] = values[i];
            edgeVal[v][u] = (double) 1.0 / values[i];
        }
        vector<double> results;
        for (int i = 0; i < queries.size(); i++) {
            if (map.count(queries[i][0]) == 0 || map.count(queries[i][1]) == 0) {
                results.push_back(-1.0);
                continue;
            }
            int u = map[queries[i][0]];
            int v = map[queries[i][1]];
            if (u == v) {
                results.push_back(1.0);
                continue;
            }
            double result = bfs(u, v, hasEdge, edgeVal);
            results.push_back(result);
        }
        return results;
    }
};

int main(void) {
    int numEquations;
    cin >> numEquations;
    vector<vector<string>> equations(numEquations, vector<string>(2));
    vector<double> values(numEquations);
    for (int i = 0; i < numEquations; i++) {
        cin >> equations[i][0] >> equations[i][1] >> values[i];
    }
    int numQueries;
    cin >> numQueries;
    vector<vector<string>> queries(numQueries, vector<string>(2));
    for (int i = 0; i < numQueries; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    Solution sol;
    vector<double> results = sol.calcEquation(equations, values, queries);
    for (auto result: results) {
        cout << result << " ";
    }
    cout << endl;
    return 0;
}
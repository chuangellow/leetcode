#include <iostream>
#include <vector>

using namespace std;

bool cmpFunc(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.first > b.first);
}

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> degrees(n, {0, 0});
        for (int i = 0; i < n; i++) degrees[i].second = i;
        for (int i = 0; i < roads.size(); i++) {
            degrees[roads[i][0]].first += 1;
            degrees[roads[i][1]].first += 1;
        }
        sort(degrees.begin(), degrees.end(), cmpFunc);
        for (int i = 0; i < n; i++) {
            cout << degrees[i].first << " " << degrees[i].second << endl;
        }
        vector<int> importance(n, 0);
        for (int i = 0; i < n; i++) {
            importance[degrees[i].second] = n - i;
        }
        long long int totalImportance = 0;
        for (int i = 0; i < roads.size(); i++) {
            totalImportance += importance[roads[i][0]];
            totalImportance += importance[roads[i][1]];
        }
        return totalImportance;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> roads(n, vector<int>(n, 0));
    Solution sol;
    cout << sol.maximumImportance(n, roads) << endl;
    return 0;
}
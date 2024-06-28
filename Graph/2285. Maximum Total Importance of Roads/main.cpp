#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> countingSort(int n, vector<pair<int, int>> degrees) {
    vector<int> buckets(n, 0);
    for (int i = 0; i < degrees.size(); i++) {
        buckets[degrees[i].first] += 1;
    }
    for (int i = 1; i < n; i++) {
        buckets[i] += buckets[i-1];
    }
    vector<pair<int, int>> out(n);
    for (int i = degrees.size() - 1; i >= 0; i--) {
        buckets[degrees[i].first] -= 1;
        out[buckets[degrees[i].first]] = degrees[i];
    }
    return out;
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
        degrees = countingSort(n, degrees);
        for (int i = 0; i < n; i++) {
            cout << degrees[i].first << " " << degrees[i].second << endl;
        }
        vector<int> importance(n, 0);
        for (int i = 0; i < n; i++) {
            importance[degrees[i].second] = i+1;
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
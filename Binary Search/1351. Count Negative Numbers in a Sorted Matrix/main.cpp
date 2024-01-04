#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid.at(i).at(j);
        }
    }
    Solution sol;
    cout << sol.countNegatives(grid) << endl;
    return 0;
}
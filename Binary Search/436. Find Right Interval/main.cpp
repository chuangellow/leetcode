#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> intervals(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> intervals.at(i).at(j);
        }
    }
    Solution sol;
    vector<int> ret = sol.findRightInterval(intervals);
    int retSize = ret.size();
    for (int i = 0; i < retSize; i++) {
        cout << ret.at(i) << " ";
    }
    cout << endl;
    return 0;
}
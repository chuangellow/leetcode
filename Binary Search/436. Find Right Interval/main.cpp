#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            int startNow = intervals.at(i).at(0);
            int endNow = intervals.at(i).at(1);
            int retIdx = -1;
            int minStart = -1;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int startCompared = intervals.at(j).at(0);
                int endCompared = intervals.at(j).at(1);
                if (startCompared >= endNow && startCompared > minStart) {
                    retIdx = j;
                    minStart = startCompared;
                }
            }
            ret.at(i) = retIdx;
        }
        return ret;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
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
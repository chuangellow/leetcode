#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOverlapped(vector<int>& intervalA, vector<int>& intervalB) {
        if (intervalA[0] > intervalB[1]) return false;
        if (intervalA[1] < intervalB[0]) return false;
        return true;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int numIntervals = intervals.size();
        vector<vector<int>> result;
        int leftVal = newInterval[0], rightVal = newInterval[1];
        bool push = false;
        for (int i = 0; i < numIntervals; i++) {
            if (isOverlapped(intervals[i], newInterval)) {
                leftVal = min(leftVal, intervals[i][0]);
                rightVal = max(rightVal, intervals[i][1]);
            }
            else {
                if (!push && newInterval[1] < intervals[i][0]) {
                    result.push_back({leftVal, rightVal});
                    push = true;
                }
                result.push_back(intervals[i]);
            }
        }
        if (!push) {
            result.push_back({leftVal, rightVal});
        }
        return result;
    }
};

int main(void) {
    int numIntervals;
    cin >> numIntervals;
    vector<vector<int>> intervals(numIntervals);
    for (int i = 0; i < numIntervals; i++) {
        vector<int> interval(2);
        cin >> interval[0] >> interval[1];
        intervals[i] = interval;
    }
    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];
    Solution sol;
    vector<vector<int>> result = sol.insert(intervals, newInterval);
    for (auto interval: result) {
        cout << interval[0] << " " << interval[1] << endl;
    }
    return 0;
}
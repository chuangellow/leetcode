#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int numIntervals = intervals.size();
        result.push_back(intervals[0]);
        for (int i = 1; i < numIntervals; i++) {
            vector<int> prevInterval = result.back();
            vector<int> currentInterval = intervals[i];
            if (currentInterval[0] <= prevInterval[1]) {
                result.pop_back();
                vector<int> newInterval {min(prevInterval[0], currentInterval[0]), max(prevInterval[1], currentInterval[1])};
                result.push_back(newInterval);
            }
            else {
                result.push_back(currentInterval);
            }
        }
        return result;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int numIntervals = intervals.size();
        int idx = 0;
        for (int i = 0; i < numIntervals; i++) {
            if (intervals[i][0] < newInterval[0]) idx++;
            else break;
        }
        intervals.insert(intervals.begin() + idx, {newInterval[0], newInterval[1]});
        return merge(intervals);
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
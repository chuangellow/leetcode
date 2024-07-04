#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
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
    Solution sol;
    vector<vector<int>> result = sol.merge(intervals);
    for (auto interval: result) {
        cout << interval[0] << " " << interval[1] << endl;
    }
    return 0;
}
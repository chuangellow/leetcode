#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(int pos, vector<pair<int, int>>& startTimes, vector<int>& endTimes, const int n) {
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = ((unsigned int) left + (unsigned int) right) >> 1;
            if (startTimes.at(mid).first < endTimes.at(pos)) left = mid + 1;
            else right = mid;
        }
        return (startTimes.at(left).first >= endTimes.at(pos))? left: -1;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> startTimes(n);
        for (int i = 0; i < n; i++) {
            startTimes.at(i).first = intervals.at(i).at(0);
            startTimes.at(i).second = i;
        }
        sort(startTimes.begin(), startTimes.end());
        vector<int> endTimes(n);
        for (int i = 0; i < n; i++) {
            endTimes.at(i) = intervals.at(startTimes.at(i).second).at(1);
        }
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            int searchIdx = binarySearch(i, startTimes, endTimes, n);
            int realIdx = (searchIdx == -1)? -1: startTimes.at(searchIdx).second;
            ret.at(startTimes.at(i).second) = realIdx;
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
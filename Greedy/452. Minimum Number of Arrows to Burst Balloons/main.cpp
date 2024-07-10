#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 1, numPoints = points.size();
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int currentEnd = points[0][1];
        for (int i = 1; i < numPoints; i++) {
            if (points[i][0] > currentEnd) {
                count++;
                currentEnd = points[i][1];
            }
        }
        return count;
    }
};

int main(void) {
    int numPoints;
    cin >> numPoints;
    vector<vector<int>> points(numPoints, vector<int>(2));
    for (int i = 0; i < numPoints; i++) {
        cin >> points[i][0] >> points[i][0];
    }
    Solution sol;
    cout << sol.findMinArrowShots(points) << endl;
    return 0;
}
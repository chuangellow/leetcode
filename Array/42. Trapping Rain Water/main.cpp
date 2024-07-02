#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;
        vector<int> leftMax(n, 0);
        int maxVal = 0;
        for (int i = 0; i < n; i++) {
            maxVal = max(maxVal, height[i]);
            leftMax[i] = maxVal;
        }
        vector<int> rightMax(n, 0);
        maxVal = 0;
        for (int i = n-1; i >= 0; i--) {
            maxVal = max(maxVal, height[i]);
            rightMax[i] = maxVal;
        }
        for (int i = 0; i < n; i++) {
            totalWater += min(leftMax[i], rightMax[i]) - height[i];
        }
        return totalWater;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    Solution sol;
    cout << sol.trap(heights) << endl;
    return 0;
}
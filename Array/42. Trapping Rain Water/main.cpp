#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> trapWater(n, 0);
        for (int i = 0; i < n; i++) trapWater[i] = height[i];
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (height[i] <= height[j]) {
                    for (int k = i+1; k < j; k++) {
                        trapWater[k] = max(trapWater[k], min(height[i], height[j]));
                    }
                    break;
                }
            }
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = i-1; j >= 0; j--) {
                if (height[i] <= height[j]) {
                    for (int k = i-1; k > j; k--) {
                        trapWater[k] = max(trapWater[k], min(height[i], height[j]));
                    }
                    break;
                }
            }
        }
        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            totalWater += (trapWater[i] - height[i]);
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
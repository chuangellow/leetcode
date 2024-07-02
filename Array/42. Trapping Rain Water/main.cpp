#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> trapWater(n, 0);
        for (int i = 0; i < n; i++) trapWater[i] = height[i];
        int left = 0;
        while (true) {
            int right = -1;
            for (int i = left + 1; i < n; i++) {
                if (trapWater[i] >= trapWater[left]) {
                    right = i;
                    break;
                }
            }
            if (right == -1) break;
            for (int i = left + 1; i < right; i++) {
                trapWater[i] = max(trapWater[i], min(trapWater[left], trapWater[right]));
            }
            left = right;
        }
        int right = n-1;
        while (true) {
            int left = -1;
            for (int i = right - 1; i >= 0; i--) {
                if (trapWater[i] >= trapWater[right]) {
                    left = i;
                    break;
                }
            }
            if (left == -1) break;
            for (int i = right - 1; i > left; i--) {
                trapWater[i] = max(trapWater[i], min(trapWater[left], trapWater[right]));
            }
            right = left;
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
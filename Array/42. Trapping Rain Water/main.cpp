#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;
        for (int i = 1; i < n-1; i++) {
            int leftTrap = -1, rightTrap = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (height[j] > height[i]) {
                    leftTrap = max(height[j], leftTrap);
                }
            }
            for (int j = i + 1; j < n; j++) {
                if (height[j] > height[i]) {
                    rightTrap = max(height[j], rightTrap);
                }
            }
            if (leftTrap == -1 || rightTrap == -1) continue;
            totalWater += min(leftTrap, rightTrap) - height[i];
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
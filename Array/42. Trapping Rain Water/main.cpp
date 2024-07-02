#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;
        int leftMax = 0, rightMax = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > leftMax) {
                    leftMax = height[left];
                }
                else {
                    totalWater += (leftMax - height[left]);
                }
                left++;
            }
            else {
                if (height[right] > rightMax) {
                    rightMax = height[right];
                }
                else {
                    totalWater += (rightMax - height[right]);
                }
                right--;
            }
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
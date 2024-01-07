#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxAmount = -1;
        int left = 0, right = n - 1;
        while (left < right) {
            int amount = (right - left) * (min(height.at(left), height.at(right)));
            maxAmount = max(amount, maxAmount);
            if (height.at(left) < height.at(right)) left++;
            else right--;
        }
        return maxAmount;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height.at(i);
    }
    Solution sol;
    cout << sol.maxArea(height) << endl;
    return 0;
}
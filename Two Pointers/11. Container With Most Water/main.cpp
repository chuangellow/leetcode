#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxAmount = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxAmount = max(maxAmount, (j - i) * min(height.at(i), height.at(j)));
            }
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
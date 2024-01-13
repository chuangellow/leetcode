#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle.at(n-1).size();
        vector<vector<int>> dp;
        dp.push_back(vector<int> {triangle.at(0).at(0)});
        if (n == 1) return dp.at(0).at(0);
        for (int i = 1; i < n; i++) {
            int size = triangle.at(i).size();
            vector<int> dpNums(size);
            for (int j = 0; j < size; j++) {
                if (j == 0) dpNums.at(j) = dp.at(i-1).at(j) + triangle.at(i).at(j);
                else if (j == size-1) dpNums.at(j) = dp.at(i-1).at(j-1) + triangle.at(i).at(j);
                else dpNums.at(j) = min(dp.at(i-1).at(j), dp.at(i-1).at(j-1)) + triangle.at(i).at(j);
            }
            dp.push_back(dpNums);
        }
        int minValue = INT32_MAX;
        for (int i = 0; i < m; i++) {
            minValue = min(dp.at(n-1).at(i), minValue);
        }
        return minValue;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> triangle;
    for (int i = 0; i < n; i++) {
        vector<int> nums(i+1);
        for (int j = 0; j < i+1; j++) {
            cin >> nums.at(j);
        }
        triangle.push_back(nums);
    }
    Solution sol;
    cout << sol.minimumTotal(triangle) << endl;
    return 0;
}
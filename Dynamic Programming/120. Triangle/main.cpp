#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        dp.at(0) = triangle.at(0).at(0);
        if (n == 0) return dp.at(0);
        for (int i = 1; i < n; i++) {
            vector<int> tempNums(n, 0);
            for (int j = 0; j < i+1; j++) {
                int temp = triangle.at(i).at(j);
                if (j == 0) temp += dp.at(j);
                else if (j == i) temp += dp.at(j-1);
                else temp += min(dp.at(j), dp.at(j-1));
                tempNums.at(j) = temp;
            }
            for (int j = 0; j < i+1; j++) {
                dp.at(j) = tempNums.at(j);
            }
        }
        int minValue = INT32_MAX;
        for (int i = 0; i < n; i++) {
            minValue = min(dp.at(i), minValue);
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
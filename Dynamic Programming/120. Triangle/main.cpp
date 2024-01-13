#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return 0;
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
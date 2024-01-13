#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void getMinTotal(int previous, int layer, int value, int* minTotal, vector<vector<int>>& triangle, int n) {
        if (layer == n) {
            *minTotal = min(*minTotal, value);
            return;
        }
        int size = triangle.at(layer).size();
        if (previous == -1) {
            for (int i = 0; i < size; i++) {
                getMinTotal(i, layer+1, value + triangle.at(layer).at(i), minTotal, triangle, n);
            }
        }
        else {
            getMinTotal(previous, layer+1, value + triangle.at(layer).at(previous), minTotal, triangle, n);
            getMinTotal(previous+1, layer+1, value + triangle.at(layer).at(previous+1), minTotal, triangle, n);
        }
        return;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int minTotal = INT32_MAX;
        int n = triangle.size();
        getMinTotal(-1, 0, 0, &minTotal, triangle, n);
        return minTotal;
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
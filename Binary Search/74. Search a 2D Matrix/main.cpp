#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m * n - 1;
        if (matrix.at(0).at(0) == target || matrix.at(n-1).at(m-1) == target)  return true;
        if (target < matrix.at(0).at(0) && target > matrix.at(n-1).at(m-1)) return false;
        while (left <= right) {
            int mid = ((unsigned int) left + (unsigned int) right) >> 1;
            int rowIdx = mid / m, colIdx = mid % m;
            int midNum = matrix.at(rowIdx).at(colIdx);
            if (midNum == target) return true;
            else if (midNum > target) right = mid - 1;
            else if (midNum < target) left = mid + 1;
        }
        return false;
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;
    int target;
    cin >> target;
    vector<vector<int> > matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix.at(i).at(j);
        }
    }
    Solution sol;
    cout << sol.searchMatrix(matrix, target) << endl;
    return 0;
}
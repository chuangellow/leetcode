#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix.at(0).size();
        if (matrix.at(0).at(0) == target || matrix.at(n-1).at(m-1) == target)  return true;
        if (target < matrix.at(0).at(0) && target > matrix.at(n-1).at(m-1)) return false;
        int rowLeft = 0, rowRight = n - 1;
        int colLeft = 0, colRight = m - 1;
        while (colLeft <= colRight && rowLeft <= rowRight) {
            int rowMid = (unsigned int) (rowLeft + rowRight) >> 1;
            int colMid = (unsigned int) (colLeft + colRight) >> 1;
            cout << "rowMid: " << rowMid << " " << "colMid: " << colMid << endl;
            int midNum = matrix.at(rowMid).at(colMid);
            if (midNum == target) return true;
            if (midNum > target) {
                if (target < matrix.at(rowMid).at(0)) {
                    rowRight = rowMid - 1;
                }
                else {
                    rowLeft = rowMid; rowRight = rowMid;
                    colRight = colMid - 1;
                }
            }
            else if (midNum < target) {
                if (target > matrix.at(rowMid).at(m - 1)) {
                    rowLeft = rowMid + 1;
                }
                else {
                    rowLeft = rowMid; rowRight = rowMid;
                    colLeft = colMid + 1;
                }
            }
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
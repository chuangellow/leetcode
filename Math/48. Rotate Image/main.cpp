#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void swapColumn(vector<vector<int>>& matrix, int colA, int colB, int n) {
        for (int i = 0; i < n; i++) {
            swap(&matrix[i][colA], &matrix[i][colB]);
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(&matrix[i][j], &matrix[j][i]);
            }
        }
        for (int i = 0; i < n / 2; i++) {
            swapColumn(matrix, i, n - i - 1, n);
        }
    }
};

int main(void) {
    int n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    Solution sol;

    cout << "Original Matrix:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "After rotating:" << endl;

    sol.rotate(matrix);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}
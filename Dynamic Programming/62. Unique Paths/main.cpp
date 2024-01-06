#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prevRow(n, 1);
        for (int i = 1; i < m; i++) {
            int temp = 1;
            for (int i = 1; i < n; i++) {
                temp = prevRow.at(i) + temp;
                prevRow.at(i) = temp;
            }
        }
        return prevRow.at(n-1);
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    Solution sol;
    cout << sol.uniquePaths(m, n) << endl;
    return 0;
}
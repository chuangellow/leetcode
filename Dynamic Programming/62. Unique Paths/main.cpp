#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void getNumPaths(int currentM, int currentN, int* numPaths, const int m, const int n) {
        if (currentM == m - 1 && currentN == n - 1) {
            *numPaths = *numPaths + 1;
            return;
        }
        if (currentM != m - 1) {
            getNumPaths(currentM+1, currentN, numPaths, m, n);
        }
        if (currentN != n - 1) {
            getNumPaths(currentM, currentN+1, numPaths, m, n);
        }
        return;
    }
    int uniquePaths(int m, int n) {
        int numPaths = 0;
        getNumPaths(0, 0, &numPaths, m, n);
        return numPaths;
    }
};

int main(void) {
    int m, n;
    cin >> m >> n;
    Solution sol;
    cout << sol.uniquePaths(m, n) << endl;
    return 0;
}
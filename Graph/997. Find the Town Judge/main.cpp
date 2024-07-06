#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<bool>> matrix(n, vector<bool>(n, false));
        if (n == 1) return 1;
        if (trust.size() == 0) return -1;
        for (auto t: trust) {
            matrix[t[0]-1][t[1]-1] = true;
        }
        for (int i = 0; i < n; i++) {
            bool beenTrusted = true;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (!matrix[j][i]) beenTrusted = false;
            }
            if (!beenTrusted) continue;
            bool trustOthers = false;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (matrix[i][j]) {
                    trustOthers = true;
                    break;
                }
            }
            if (trustOthers) continue;
            return i+1;
        }
        return -1;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> trust(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> trust[i][0] >> trust[i][1];
    Solution sol;
    cout << sol.findJudge(n, trust) << endl;
}
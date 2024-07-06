#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<bool>> matrix(n, vector<bool>(n, false));
        if (n == 1) return 1;
        if (trust.size() == 0) return -1;
        vector<int> inDegrees(n, 0);
        vector<int> outDegrees(n, 0);
        for (auto t: trust) {
            inDegrees[t[1]-1]++;
            outDegrees[t[0]-1]++;
        }
        for (int i = 0; i < n; i++) {
            if (inDegrees[i] == n-1 && outDegrees[i] == 0) return i;
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
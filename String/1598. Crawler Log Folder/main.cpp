#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for (auto log: logs) {
            if (log.compare("../") == 0) {
                count = max(0, count-1);
            }
            else if (log.compare("./") != 0) {
                count++;
            }
        }
        return count;
    }
};

int main(void) {
    int numLogs;
    cin >> numLogs;
    vector<string> logs(numLogs);
    for (int i = 0; i < numLogs; i++) cin >> logs[i];
    Solution sol;
    cout << sol.minOperations(logs) << endl;
    return 0;
}
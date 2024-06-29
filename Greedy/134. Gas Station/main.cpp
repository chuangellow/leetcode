#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            int totalGas = gas[i] - cost[i], pos = (i + 1) % n;
            while (pos != i) {
                if (totalGas < 0) break;
                totalGas += gas[pos];
                totalGas -= cost[pos];
                pos = (pos + 1) % n;
            }
            if (pos == i && totalGas >= 0) return pos;
        }
        return -1;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> gas(n);
    for (int i = 0; i < n; i++) cin >> gas[i];
    vector<int> cost(n);
    for (int i = 0; i < n; i++) cin >> cost[i];
    Solution sol;
    cout << sol.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
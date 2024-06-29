#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int idx = 0;
        while (true) {
            if (gas[idx] < cost[idx]) {
                if ((idx + 1) % n > idx) idx = (idx + 1) % n;
                else return -1;
                continue;
            }
            int moveIdx = (idx + 1) % n;
            int currentGas = gas[idx] - cost[idx];
            while (moveIdx != idx) {
                if (currentGas < 0) break;
                currentGas += gas[moveIdx];
                currentGas -= cost[moveIdx];
                moveIdx = (moveIdx + 1) % n;
            }
            if (moveIdx == idx && currentGas >= 0) return idx;
            if (moveIdx <= idx) break;
            idx = moveIdx;
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
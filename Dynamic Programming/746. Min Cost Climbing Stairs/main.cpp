#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void findMinCost(int pos, int totalCost, int* minCost, vector<int>& cost, const int n) {
        if (pos >= n) {
            *minCost = (totalCost < *minCost)? totalCost: *minCost;
            return;
        }
        findMinCost(pos + 1, totalCost + cost.at(pos), minCost, cost, n);
        findMinCost(pos + 2, totalCost + cost.at(pos), minCost, cost, n);
        return;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int minCost = INT32_MAX;
        findMinCost(0, 0, &minCost, cost, n);
        findMinCost(1, 0, &minCost, cost, n);
        return minCost;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost.at(i);
    }
    Solution sol;
    cout << sol.minCostClimbingStairs(cost) << endl;
    return 0;
}
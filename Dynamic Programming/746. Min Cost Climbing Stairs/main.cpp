#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 2) return min(cost.at(0), cost.at(1));
        int firstResult = cost.at(0), secondResult = cost.at(1);
        int finalResult = 0;
        for (int i = 3; i <= n; i++) {
            finalResult = min(firstResult + cost.at(i - 1), secondResult + cost.at(i - 1));
            firstResult = secondResult;
            secondResult = finalResult;
        }
        return min(firstResult, secondResult);
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
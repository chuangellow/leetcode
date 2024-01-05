#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
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
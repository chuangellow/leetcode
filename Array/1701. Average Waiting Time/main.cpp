#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double averageWaitingTime = 0;
        int currentTime = 0;
        for (auto customer: customers) {
            currentTime = max(currentTime, customer[0]);
            currentTime += customer[1];
            averageWaitingTime += currentTime - customer[0];
        }
        return averageWaitingTime / customers.size();
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> customers(n);
    for (int i = 0; i < n; i++) {
        cin >> customers[i][0] >> customers[i][1];
    }
    Solution sol;
    cout << sol.averageWaitingTime(customers) << endl;
    return 0;
}
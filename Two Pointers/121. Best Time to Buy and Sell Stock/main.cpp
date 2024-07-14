#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int slow = 0, fast = slow + 1;
        int maxVal = 0;
        while (slow < n && fast < n) {
            if (prices[fast] <= prices[slow]) {
                slow = fast;
                fast = fast + 1;
            }
            else {
                maxVal = max(maxVal, prices[fast] - prices[slow]);
                fast += 1;
            }
        }
        return maxVal;
    }
};

int main(void) {
    int numPrices;
    cin >> numPrices;
    vector<int> prices(numPrices);
    for (int i = 0; i < numPrices; i++) cin >> prices[i];
    Solution sol;
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
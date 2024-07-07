#include <iostream>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int currentBottles = numBottles;
        int numDrinks = numBottles;
        while ((currentBottles / numExchange) > 0) {
            numDrinks += (currentBottles / numExchange);
            currentBottles = (currentBottles / numExchange) + (currentBottles % numExchange);
        }
        return numDrinks;
    }
};

int main(void) {
    int numBottles, numExchange;
    cin >> numBottles >> numExchange;
    Solution sol;
    cout << sol.numWaterBottles(numBottles, numExchange) << endl;
    return 0;
}
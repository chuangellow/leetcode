#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int, int>> sortedRatings(n);
        vector<int> candies(n, 1);
        for (int i = 0; i < n; i++) sortedRatings[i] = {ratings[i], i};
        sort(sortedRatings.begin(), sortedRatings.end());
        for (int i = 0; i < n; i++) {
            int idx = sortedRatings[i].second;
            if (idx > 0 && ratings[idx] > ratings[idx-1] && candies[idx] <= candies[idx-1]) candies[idx] = candies[idx-1] + 1;
            if (idx < n - 1 && ratings[idx] > ratings[idx+1] && candies[idx] <= candies[idx+1]) candies[idx] = candies[idx+1] + 1;
        }
        int numCandies = 0;
        for (int i = 0; i < n; i++) {
            numCandies += candies[i];
        }
        return numCandies;
    }
};

int main(void) {
    int numRatings;
    cin >> numRatings;
    vector<int> ratings(numRatings);
    for (int i = 0; i < numRatings; i++) cin >> ratings[i];
    Solution sol;
    cout << sol.candy(ratings) << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int binartSearch(vector<int>& secondNums, int targetLeft, int targetRight, int n) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = ((unsigned int) left + (unsigned int) right) >> 1;
            if (secondNums[mid] < targetLeft) left = mid + 1;
            else {
                if (targetRight < secondNums[mid]) right = mid;
                else left = mid + 1;
            }
        }
        if (left == n) return -1;
        return (secondNums[left] >= targetLeft && secondNums[left] > targetRight)? left: -1;
    }
    int linearSearch(vector<int>& secondNums, int targetLeft, int targetRight, int n) {
        for (int i = 0; i < n; i++) {
            if (secondNums[i] >= targetLeft && secondNums[i] > targetRight) return i;
        }
        return -1;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> secondNums = {pairs[0][1]};
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (pairs[i][0] > secondNums[len-1]) {
                secondNums.push_back(pairs[i][1]);
                len++;
            }
            else {
                int idx = binartSearch(secondNums, pairs[i][0], pairs[i][1], len);
                if (idx != -1) secondNums[idx] = pairs[i][1];
            }
        }
        return len;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> pairs(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> pairs[i][0] >> pairs[i][1];
    }
    Solution sol;
    cout << sol.findLongestChain(pairs) << endl;
}
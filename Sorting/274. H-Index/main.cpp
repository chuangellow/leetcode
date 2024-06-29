#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int maxVal = citations[0];
        int n = citations.size();
        for (int i = 1; i < n; i++) {
            maxVal = max(maxVal, citations[i]);
        }
        vector<int> table(maxVal+1, 0);
        for (auto citation: citations) {
            table[citation] += 1;
        }
        int count = 0, i = maxVal;
        for (; i >= 0; i--) {
            count += table[i];
            if (count >= i) break;
        }
        return i;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> citations(n);
    for (int i = 0; i < n; i++) cin >> citations[i];
    Solution sol;
    cout << sol.hIndex(citations) << endl;
    return 0;
}
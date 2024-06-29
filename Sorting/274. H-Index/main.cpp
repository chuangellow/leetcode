#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> table(n+1, 0);
        for (auto citation: citations) {
            table[min(citation, n)] += 1;
        }
        int count = 0, i = n;
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
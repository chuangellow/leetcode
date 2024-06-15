#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end(), std::greater<>());
        int count = 0;
        int boxIdx = 0;
        for (int i = 0; i < warehouse.size(); i++) {
            if (boxIdx >= boxes.size()) break;
            while (boxIdx < boxes.size() && boxes[boxIdx] > warehouse[i]) {
                boxIdx += 1;
            }
            if (boxIdx < boxes.size()) {
                count += 1;
                boxIdx += 1;
            }
        }
        return count;
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> boxes(n);
    for (int i = 0; i < n; i++) cin >> boxes[i];
    vector<int> houses(m);
    for (int i = 0; i < m; i++) cin >> houses[i];
    Solution sol;
    cout << sol.maxBoxesInWarehouse(boxes, houses) << endl;
    return 0;
}
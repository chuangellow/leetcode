#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());
        int count = 0;
        vector<bool> empty(warehouse.size(), true);
        for (int i = 0; i < boxes.size(); i++) {
            int insertIdx = -1;
            for (int j = 0; j < warehouse.size(); j++) {
                if (warehouse[j] < boxes[i]) break;
                if (empty[j] && boxes[i] <= warehouse[j]) {
                    insertIdx = j;
                }
            }
            if (insertIdx != -1) {
                empty[insertIdx] = false;
                count += 1;
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
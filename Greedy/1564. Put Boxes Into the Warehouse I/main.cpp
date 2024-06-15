#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());
        vector<int> minArr(warehouse.size(), 0);
        minArr[0] = warehouse[0];
        for (int i = 1; i < warehouse.size(); i++) {
            minArr[i] = min(minArr[i-1], warehouse[i]);
        }
        int lastHouse = -1;
        for (int i = warehouse.size()-1; i >= 0; i--) {
            if (minArr[i] >= boxes[0]) {
                lastHouse = i;
                break;
            }
        }
        if (lastHouse == -1) return 0;
        int count = 1;
        lastHouse -= 1;
        for (int i = 1; i < boxes.size(); i++) {
            cout << count << " " << lastHouse << endl;
            if (lastHouse < 0) break;
            while (lastHouse >= 0 && minArr[lastHouse] < boxes[i]) {
                lastHouse -= 1;
            }
            if (lastHouse >= 0) {
                lastHouse -= 1;
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
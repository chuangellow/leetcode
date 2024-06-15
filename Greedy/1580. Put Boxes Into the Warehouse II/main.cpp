#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end(), std::greater<>());
        int left = 0, right = warehouse.size() - 1;
        int boxIdx = 0;
        int count = 0;
        while (left <= right) {
            int maxIdx = -1;
            if (warehouse[left] > warehouse[right]) maxIdx = left;
            else maxIdx = right;
            if (boxIdx >= boxes.size()) break;
            while (boxIdx < boxes.size() && boxes[boxIdx] > warehouse[maxIdx]) {
                boxIdx += 1;
            }
            if (boxIdx < boxes.size()) {
                boxIdx += 1;
                count += 1;
            }
            if (maxIdx == left) left += 1;
            else right -= 1;
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
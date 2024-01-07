#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> height;
    for (int i = 0; i < n; i++) {
        cin >> height.at(i);
    }
    Solution sol;
    cout << sol.maxArea(height) << endl;
    return 0;
}
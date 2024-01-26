#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int difference;
    cin >> difference;
    Solution sol;
    cout << sol.longestSubsequence(arr, difference) << endl;
    return 0;
}
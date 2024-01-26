#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> hashTable;
        hashTable[arr[0]] = 1;
        int finalMaxValue = 1;
        int temp;
        for (int i = 1; i < n; i++) {
            temp = hashTable.count(arr[i] - difference) ? hashTable[arr[i] - difference] + 1 : 1;
            hashTable[arr[i]] = max(hashTable[arr[i]], temp);
            finalMaxValue = max(finalMaxValue, temp);
        }
        return finalMaxValue;
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
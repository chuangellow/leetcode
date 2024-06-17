#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] += 1;
        }
        vector<pair<int, int>> elements(map.begin(), map.end());
        sort(elements.begin(), elements.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        vector<int> out;
        int count = 0;
        for (pair<int, int> element: elements) {
            if (count >= k) return out;
            out.push_back(element.first);
            count += 1;
        }
        return out;
    }
};

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    vector<int> ret = sol.topKFrequent(nums, k);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}
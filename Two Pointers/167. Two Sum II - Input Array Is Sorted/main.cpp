#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(int left, int right, int target, vector<int>& numbers) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (numbers[mid] == target) return mid;
            else if (numbers[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> result;
        for (int i = 0; i < n-1; i++) {
            int idx = search(i+1, n-1, target-numbers[i], numbers);
            if (idx != -1) {
                result.push_back(i+1);
                result.push_back(idx+1);
                return result;
            }
        }
        return result;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int target;
    cin >> target;
    Solution sol;
    vector<int> result = sol.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) cout << result[i] << ((i == result.size()-1)? " ": "");
    cout << endl;
    return 0;
}
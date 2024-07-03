#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0, right = n - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                return {left+1, right+1};
            }
            else if (numbers[left] + numbers[right] > target) {
                right--;
            }
            else {
                left++;
            }
        }
        return {};
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
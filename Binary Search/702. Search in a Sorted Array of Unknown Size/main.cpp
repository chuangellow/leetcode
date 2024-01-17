#include <iostream>
#include <vector>

using namespace std;

class ArrayReader {
private:
    vector<int> nums;
    int size;
public:
    ArrayReader(vector<int> nums) : nums(nums), size(nums.size()) {}
    int get(int index) {
        if (index >= size) {
            return INT_MAX;
        }
        return nums[index];
    }
};

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    ArrayReader reader(nums);
    int target;
    cin >> target;

    Solution sol;
    cout << sol.search(reader, target) << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class ArrayReader {
private:
    vector<int> nums;
    int size;
public:
    ArrayReader(vector<int> nums) : nums(nums), size(nums.size()) {}
    int get(int index) const {
        if (index >= size) {
            return INT_MAX;
        }
        return nums[index];
    }
};

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0, right = 1;
        while (reader.get(right) < target) {
            left = right;
            right <<= 1;
        }
        while (left <= right) {
            int mid = ((unsigned int) left + (unsigned int) right) >> 1;
            if (reader.get(mid) == target) return mid;
            else if (reader.get(mid) < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
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
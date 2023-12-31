#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		// Time complexity: O(nlgn)
		// Space complexity: O(1)
		int n = nums.size();
		if (n == 0 || n == 1 && nums.at(0) != target) return -1;
		int left = 0, right = n - 1;
		while (left <= right) {
			// Why we use the left <= right instead of left < right?
			int mid = (left + right) / 2;
			if (nums.at(mid) == target) return mid;
			else if (nums.at(mid) < target) left = mid + 1;
			else right = mid - 1;
		}
		return -1;
    }
};

int main(void) {
	int n, target;
	cin >> n >> target;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	Solution solution;
	cout << solution.search(nums, target) << endl;
	return 0;
}

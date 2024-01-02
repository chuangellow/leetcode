#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int left = 0, right = n - 1;
		while (left <= right) {
			int mid = (unsigned int) (left + right) >> 1;
			if (nums.at(mid) <= mid) right = mid - 1;
			else left = mid + 1;
		}
		return nums.at(right + 1);
    }
};

int main(void) {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	Solution sol;
	cout << sol.findDuplicate(nums) << endl;
	return 0;
}

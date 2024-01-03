#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) return 0;
		int left = 0, right = n - 1;
		while (left <= right) {
			int mid = (unsigned int) (left + right) >> 1;
			if (mid - 1 < 0 && nums.at(mid) > nums.at(mid+1)) return mid;
			if (mid + 1 >= n && nums.at(mid) > nums.at(mid-1)) return mid;
			if (mid - 1 >= 0 && mid + 1 < n && nums.at(mid) > nums.at(mid-1) && nums.at(mid) > nums.at(mid+1)) return mid;
			if (mid - 1 >= 0 && nums.at(mid-1) > nums.at(mid)) right = mid - 1;
			else if (mid + 1 < n && nums.at(mid+1) > nums.at(mid)) left = mid + 1;
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
	Solution sol;
	cout << sol.findPeakElement(nums) << endl;
	return 0;
}

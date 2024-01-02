#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			bool flag = true;
			if (i - 1 >= 0 && nums.at(i) <= nums.at(i-1)) flag = false;
			if (i + 1 <= n - 1 && nums.at(i) <= nums.at(i+1)) flag = false;
			if (flag) return i;
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

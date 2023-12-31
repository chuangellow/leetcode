#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findPivot(vector<int>& nums, int n) {
		int left = 0, right = n - 1;
		int rightMostNum = nums.at(n - 1);
		while (left <= right) {
			int mid = (unsigned int) (left + right) >> 1;
			if (nums.at(mid) > rightMostNum) left = mid + 1;
			else right = mid - 1;
		}
		return right + 1;
	}
	int getRealIndex(int index, int pivot, int n) {
		return (index + pivot) % n;
	}
    int search(vector<int>& nums, int target) {
		int n = nums.size();
        if (n == 0) return -1;
        if (n == 1 && nums.at(0) == target) return 0;
		if (n == 1 && nums.at(0) != target) return -1;
		int pivot = findPivot(nums, n);
		int left = 0, right = n - 1;
		while (left <= right) {
			int mid = (unsigned int) (left + right) >> 1;
			int realMid = getRealIndex(mid, pivot, n);
			cout << nums.at(realMid) << endl;
			if (nums.at(realMid) == target) return realMid;
			else if (nums.at(realMid) < target) left = mid + 1;
			else right = mid - 1;
		}
		return -1;
    }
};

int main(void) {
	int target, n;
	cin >> target >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	Solution sol;
	cout << sol.search(nums, target) << endl;
	return 0;
}

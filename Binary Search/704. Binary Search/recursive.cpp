#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int recursiveSearch(int left, int right, vector<int>& nums, int target) {
		if (left > right) return -1;
		int mid = (unsigned int) (left + right) >> 1;
		if (nums.at(mid) == target) return mid;
		else if (nums.at(mid) > target) return recursiveSearch(left, mid-1, nums, target);
		else return recursiveSearch(mid+1, right, nums, target);
	}
    int search(vector<int>& nums, int target) {
		int n = nums.size();
		if (n == 0 || n == 1 && nums.at(0) != target) return -1;
		return recursiveSearch(0, n-1, nums, target);
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

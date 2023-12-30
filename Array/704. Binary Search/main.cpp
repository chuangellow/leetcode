#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
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

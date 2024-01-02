#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int getNumBits(int n) {
		int count = 0;
		while (n > 0) {
			n = n /= 2;
			count++;
		}
		return count;
	}
	void setBit(int* num, int bit) {
		*num = *num | (0x1 << bit);
		return;
	}
	int getBit(int num, int bit) {
		return (num >> bit & 0x1);
	}
    int findDuplicate(vector<int>& nums) {
		int n = nums.size();
		int maxBits = getNumBits(n-1);
		int mask = 0;
		for (int bit = 0; bit <= maxBits; bit++) {
			int origSum = 0;
			for (int num = 1; num < n; num++) {
				origSum += getBit(num, bit);
			}
			int numBitSum = 0;
			for (int idx = 0; idx < n; idx++) {
				numBitSum += getBit(nums.at(idx), bit);
			}
			if ((numBitSum - origSum) > 0) setBit(&mask, bit);
		}
		return mask;
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

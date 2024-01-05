#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void getMaxPoints(int currentPoint, int* maxPoint, vector<int> nums) {
        int n = nums.size();
        if (n == 0) {
            *maxPoint = max(*maxPoint, currentPoint);
            return;
        }
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                if (i != j && abs(nums.at(j) - nums.at(i)) != 1) {
                    temp.push_back(nums.at(j));
                }
            }
            getMaxPoints(currentPoint + nums.at(i), maxPoint, temp);
        }
        return;
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxPoint = -1;
        getMaxPoints(0, &maxPoint, nums);
        return maxPoint;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums.at(i);
    }
    Solution sol;
    cout << sol.deleteAndEarn(nums) << endl;
    return 0;
}
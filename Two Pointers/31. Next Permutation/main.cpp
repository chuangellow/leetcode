#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void getPermutations(int pos, vector<bool>& mask, vector<int>& perm, vector<vector<int>>& perms, vector<int>& nums, const int n) {
        if (pos == n) {
            perms.push_back(perm);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (mask.at(i)) {
                perm.push_back(nums.at(i));
                mask.at(i) = false;
                getPermutations(pos+1, mask, perm, perms, nums, n);
                mask.at(i) = true;
                perm.pop_back();
            }
        }
        return;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp.at(i) = nums.at(i);
        }
        sort(temp.begin(), temp.end());
        vector<bool> mask(n, true);
        vector<int> perm;
        vector<vector<int>> perms;
        getPermutations(0, mask, perm, perms, temp, n);
        int size = perms.size();
        int idx = -1;
        for (int i = 0; i < size; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (perms.at(i).at(j) != nums.at(j)) flag = false;
            }
            if (flag) idx = i;
        }
        int nextIdx = (idx + 1) % n;
        for (int i = 0; i < n; i++) {
            nums.at(i) = perms.at(nextIdx).at(i);
        }
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
    sol.nextPermutation(nums);
    for (int i = 0; i < n; i++) {
        cout << nums.at(i) << " ";
    }
    cout << endl;
    return 0;
}
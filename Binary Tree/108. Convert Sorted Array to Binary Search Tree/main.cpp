#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void showTree(TreeNode* node) {
        if (!node) {
            cout << "null ";
            return;
        }
        cout << node->val << " ";
        showTree(node->left);
        showTree(node->right);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        return recursiveBuild(0, size-1, nums);
    }
    TreeNode* recursiveBuild(int left, int right, vector<int>& nums) {
        if (left > right) return nullptr;
        int mid = (left + right) >> 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = recursiveBuild(left, mid-1, nums);
        root->right = recursiveBuild(mid+1, right, nums);
        return root;
    }
    void freeNode(TreeNode* root) {
        if (root == nullptr) return;
        freeNode(root->left);
        freeNode(root->right);
        delete root;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(nums);
    sol.showTree(root);
    return 0;
}
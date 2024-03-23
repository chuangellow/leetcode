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
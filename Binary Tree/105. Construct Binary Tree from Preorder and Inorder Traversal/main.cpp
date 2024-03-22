#include <iostream>
#include <unordered_set>
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
        if (!node) return;
        cout << node->val << " ";
        showTree(node->left);
        showTree(node->right);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
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
    vector<int> preorder(n);
    for (int i = 0; i < n; i++) cin >> preorder[i];
    vector<int> inorder(n);
    for (int i = 0; i < n; i++) cin >> inorder[i];
    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);
    sol.showTree(root);
    return 0;
}
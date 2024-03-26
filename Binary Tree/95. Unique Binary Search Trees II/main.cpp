#include <iostream>
#include <vector>
#include <string>
#include <stack>

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
    void inorderTraverse(TreeNode *root) {
        if (root == nullptr) return;
        inorderTraverse(root->left);
        cout << root->val << " ";
        inorderTraverse(root->right);
    }
    vector<TreeNode*> generateTrees(int n) {
    }
};

int main(void) {
    int n;
    cin >> n;
    Solution sol;
    vector<TreeNode*> ans;
    ans = sol.generateTrees(n);
    for (TreeNode* root: ans) {
        sol.inorderTraverse(root);
        cout << endl;
    }
}
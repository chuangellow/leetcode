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
    vector<TreeNode*> genTree(int left, int right) {
        if (left > right) return {nullptr};
        vector<TreeNode*> roots;
        for (int i = left; i <= right; i++) {
            vector<TreeNode*> leftRoots = genTree(left, i-1);
            vector<TreeNode*> rightRoots = genTree(i+1, right);
            for (TreeNode* leftRoot: leftRoots) {
                for (TreeNode* rightRoot: rightRoots) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    roots.push_back(root);
                }
            }
        }
        return roots;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> roots;
        roots = genTree(1, n);
        return roots;
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
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(vector<int>& nums) {
    int n = nums.size();
    TreeNode *root = new TreeNode(nums[0]);
    queue<TreeNode *> q;
    q.push(root);
    int currentIdx = 1;
    while (currentIdx < n) {
        TreeNode *parent = q.front();
        q.pop();
        TreeNode *left = new TreeNode(nums[currentIdx++]);
        parent->left = left;
        q.push(left);
        if (currentIdx >= n) break;
        TreeNode *right = new TreeNode(nums[currentIdx++]);
        parent->right = right;
        q.push(right);
    }
    return root;
}

void preorderTraversal(TreeNode *root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

class Solution {
public:
    int solve(TreeNode* root, int* maxPathSum) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return root->val;
        vector<int> paths;
        int leftVal, rightVal;
        paths.push_back(root->val);
        if (root->left != nullptr) {
            leftVal = solve(root->left, maxPathSum);
            *maxPathSum = max(*maxPathSum, leftVal);
        }
        if (root->right != nullptr) {
            rightVal = solve(root->right, maxPathSum);
            *maxPathSum = max(*maxPathSum, rightVal);
        }
        if (root->left != nullptr) {
            paths.push_back(root->val + leftVal);
        }
        if (root->right != nullptr) {
            paths.push_back(root->val + rightVal);
        }
        int maxVal = paths[0];
        for (auto path: paths) {
            maxVal = max(path, maxVal);
        }
        *maxPathSum = max(*maxPathSum, maxVal);
        if (root->left != nullptr && root->right != nullptr) {
            *maxPathSum = max(leftVal + rightVal + root->val, *maxPathSum);
        }
        return maxVal;
    }
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT32_MIN;
        int result = solve(root, &maxPathSum);
        return max(result, maxPathSum);
    }
};

int main(void) {
    int n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    TreeNode *root = buildTree(nums);
    Solution sol;
    cout << sol.maxPathSum(root) << endl;
}
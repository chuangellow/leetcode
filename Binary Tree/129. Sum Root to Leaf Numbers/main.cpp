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
    int totalSum = 0;
    void goToLeaf(TreeNode* root, int currentSum) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            currentSum = currentSum * 10 + root->val;
            totalSum += currentSum;
            return;
        }
        goToLeaf(root->left, currentSum * 10 + root->val);
        goToLeaf(root->right, currentSum * 10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        goToLeaf(root, 0);
        return totalSum;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    TreeNode *root = buildTree(nums);
    Solution sol;
    cout << sol.sumNumbers(root) << endl;
}
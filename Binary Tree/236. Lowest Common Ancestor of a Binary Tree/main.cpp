#include <iostream>
#include <vector>
#include <stack>
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

TreeNode *findNode(TreeNode *root, int val) {
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode* currentNode = s.top();
        s.pop();
        if (currentNode->val == val) return currentNode;
        if (currentNode->right != nullptr) s.push(currentNode->right);
        if (currentNode->left != nullptr) s.push(currentNode->left);
    }
    return nullptr;
}

class Solution {
public:
    TreeNode* result = nullptr;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        int left = dfs(root->left, p, q)? 1: 0;
        int right = dfs(root->right, p, q)? 1: 0;
        int mid = (root == p) || (root == q)? 1: 0;
        if (left + right + mid >= 2) result = root;
        return (left + right + mid) > 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return result;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    TreeNode *root = buildTree(nums);
    int pVal, qVal;
    cin >> pVal >> qVal;
    TreeNode* p = findNode(root, pVal);
    TreeNode* q = findNode(root, qVal);
    Solution sol;
    cout << sol.lowestCommonAncestor(root, p, q)->val << endl;
    return 0;
}
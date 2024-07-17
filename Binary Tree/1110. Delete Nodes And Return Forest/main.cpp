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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<TreeNode*, TreeNode*> result;
    bool found = false;
    bool dfs(TreeNode* node, int val) {
        if (node == nullptr) return false;
        if (node->val == val) {
            result.first = node->left;
            result.second = node->right;
            found = true;
            return true;
        }
        bool left = dfs(node->left, val);
        bool right = dfs(node->right, val);
        if (left) node->left = nullptr;
        if (right) node->right = nullptr;
        return false; 
    }
    void deleteNode(vector<TreeNode*>& nodes, int val) {
        for (int i = 0; i < nodes.size(); i++) {
            TreeNode* node = nodes[i];
            found = false;
            dfs(node, val);
            if (found) {
                if (node->val == val) nodes.erase(nodes.begin() + i);
                if (result.first != nullptr) nodes.push_back(result.first);
                if (result.second != nullptr) nodes.push_back(result.second);
                return;
            }
        }
        return;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == nullptr) return {root}; 
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        for (int i = 0; i < to_delete.size(); i++) {
            deleteNode(nodes, to_delete[i]);
        }
        return nodes;
    }
};

int main(void) {
    int numNodes;
    cin >> numNodes;
    vector<int> nums(numNodes);
    for (int i = 0; i < numNodes; i++) cin >> nums[i];
    int numDels;
    cin >> numDels;
    vector<int> to_delete(numDels);
    for (int i = 0; i < numDels; i++) cin >> to_delete[i];
    TreeNode* root = buildTree(nums);
    Solution sol;
    vector<TreeNode*> nodes = sol.delNodes(root, to_delete);
    for (auto& node: nodes) {
        preorderTraversal(node);
    }
    return 0;
}
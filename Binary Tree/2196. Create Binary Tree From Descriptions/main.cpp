#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> set;
        unordered_map<TreeNode*, TreeNode*> parents;
        int n = descriptions.size();
        TreeNode* root = nullptr;
        for (int i = 0; i < n; i++) {
            int parent = descriptions[i][0], child = descriptions[i][1], isLeft = descriptions[i][2];
            TreeNode *parentNode, *childNode;
            if (set.count(child) != 0) {
                childNode = set[child];
            }
            else {
                childNode = new TreeNode(child);
                set[child] = childNode;
            }
            if (set.count(parent) != 0) {
                parentNode = set[parent];
            }
            else {
                parentNode = new TreeNode(parent);
                set[parent] = parentNode;
            }
            if (isLeft == 1) {
                parentNode->left = childNode;
            }
            else {
                parentNode->right = childNode;
            }
            parents[childNode] = parentNode;
            if (parents.count(parentNode) == 0) parents[parentNode] = nullptr;
        }
        for (auto parent: parents) {
            if (parent.second == nullptr) return parent.first;
        }
        return nullptr;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<vector<int>> descriptions(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        int parent, child, isLeft;
        cin >> parent >> child >> isLeft;
    }
    Solution sol;
    TreeNode *root = sol.createBinaryTree(descriptions);
    preorderTraversal(root);
    return 0;
}
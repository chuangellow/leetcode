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

TreeNode* buildTree(const vector<string>& nodeValues) {
    if (nodeValues.empty()) return nullptr;

    TreeNode* root = new TreeNode(stoi(nodeValues[0])); // Assuming the first value is always the root and is not null
    vector<TreeNode*> nodes{root};

    for (size_t i = 1; i < nodeValues.size(); ++i) {
        if (nodeValues[i] != "null") {
            TreeNode* node = new TreeNode(stoi(nodeValues[i]));
            if (i % 2 == 1) { // Odd index, left child
                nodes[(i - 1) / 2]->left = node;
            } else { // Even index, right child
                nodes[(i - 2) / 2]->right = node;
            }
            nodes.push_back(node);
        }
    }

    return root;
}

class Solution {
public:
    void traverse(TreeNode* node, int level, vector<vector<int>>& nums, int *size) {
        if (node == nullptr) return;
        if (level > *size) {
            vector<int> num;
            num.push_back(node->val);
            nums.push_back(num);
            *size = *size + 1;
        }
        else {
            nums[level].push_back(node->val);
        }
        traverse(node->left, level+1, nums, size);
        traverse(node->right, level+1, nums, size);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> nums;
        int size = -1;
        traverse(root, 0, nums, &size);
        return nums;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<string> nodeValues(n);
    for (int i = 0; i < n; i++) {
        cin >> nodeValues[i];
    }
    TreeNode* root = buildTree(nodeValues);
    Solution sol;
    vector<vector<int>> ans;
    ans = sol.levelOrder(root);
    return 0;
}
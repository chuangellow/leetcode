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
    void traverse(TreeNode* node, int level, int *maxDepth) {
        if (node == nullptr) return;
        *maxDepth = max(*maxDepth, level);
        traverse(node->left, level+1, maxDepth);
        traverse(node->right, level+1, maxDepth);
        return;
    }
    int maxDepth(TreeNode* root) {
        int maxDepth = -1;
        traverse(root, 0, &maxDepth);
        return maxDepth;
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
    cout << sol.maxDepth(root) << endl;
    return 0;
}
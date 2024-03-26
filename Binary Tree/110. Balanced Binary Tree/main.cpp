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
    pair<int, bool> getDepth(TreeNode* root) {
        if (!root) return {0, true};
        pair<int, bool> left = getDepth(root->left);
        if (!left.second) return {0, false};
        pair<int, bool> right = getDepth(root->right);
        if (!right.second) return {0, false};
        if (abs(left.first - right.first) > 1) return {0, false};
        return {max(left.first, right.first) + 1, true};
    }
    bool isBalanced(TreeNode* root) {
        return getDepth(root).second;
    }
};

int main(void) {
    int numNodes, target;
    cin >> numNodes >> target;
    vector<string> nodeValues(numNodes);
    for (int i = 0; i < numNodes; i++) cin >> nodeValues[i];
    TreeNode* root = buildTree(nodeValues);
    Solution sol;
    cout << sol.isBalanced(root) << endl;
}
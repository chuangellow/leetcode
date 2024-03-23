#include <iostream>
#include <unordered_set>
#include <unordered_map>
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
private:
    stack<TreeNode*> nodes;
public:
    void showTree(TreeNode* node) {
        if (!node) {
            cout << "null ";
            return;
        }
        cout << node->val << " ";
        showTree(node->left);
        showTree(node->right);
    }
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr && !(nodes.empty())) {
            root->right = nodes.top();
            nodes.pop();
            flatten(root->right);
            return;
        }
        if (root->right != nullptr) {
            nodes.push(root->right);
        }
        root->right = root->left;
        root->left = nullptr;
        if (root->right == nullptr && !(nodes.empty())) {
            root->right = nodes.top();
            nodes.pop();
        }
        flatten(root->right);
    }
    void freeNode(TreeNode* root) {
        if (root == nullptr) return;
        freeNode(root->left);
        freeNode(root->right);
        delete root;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<string> nodeValues(n);
    for (int i = 0; i < n; i++) cin >> nodeValues[i];
    TreeNode *root = buildTree(nodeValues);
    Solution sol;
    sol.flatten(root);
    sol.showTree(root);
    return 0;
}
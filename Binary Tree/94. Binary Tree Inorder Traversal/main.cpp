#include <iostream>
#include <vector>

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
    void traverse(TreeNode *currentNode, vector<int>& ans) {
        if (currentNode == nullptr) return;
        traverse(currentNode->left, ans);
        ans.push_back(currentNode->val);
        traverse(currentNode->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
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

int main(void) {
    int n;
    cin >> n;
    vector<string> nodeValues(n);
    for (int i = 0; i < n; i++) {
        cin >> nodeValues[i];
    }
    TreeNode* root = buildTree(nodeValues);
    Solution sol;
    vector<int> ans = sol.inorderTraversal(root);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
}
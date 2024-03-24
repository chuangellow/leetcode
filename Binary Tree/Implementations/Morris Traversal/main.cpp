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

TreeNode* findRightMost(TreeNode* root) {
    TreeNode* current = root->left;
    while (current->right != nullptr && current->right != root) {
        current = current->right;
    }
    return current;
}

void inorderMorrisTraverse(TreeNode* root) {
    TreeNode* current = root;
    while (current) {
        if (!current->left) {
            cout << current->val << " ";
            current = current->right;
        }
        else {
            TreeNode* rightMost = findRightMost(current);
            if (rightMost->right == nullptr) {
                rightMost->right = current;
                current = current->left;
            } 
            else {
                cout << current->val << " ";
                rightMost->right = nullptr;
                current = current->right;
            }
        }
    }
}

void preorderMorrisTraverse(TreeNode* root) {
    TreeNode* current = root;
    while (current) {
        if (!current->left) {
            cout << current->val << " ";
            current = current->right;
        }
        else {
            TreeNode* rightMost = findRightMost(current);
            if (rightMost->right == nullptr) {
                cout << current->val << " ";
                rightMost->right = current;
                current = current->left;
            } 
            else {
                rightMost->right = nullptr;
                current = current->right;
            }
        }
    }
}

void inorderTraverse(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraverse(root->left);
    cout << root->val << " ";
    inorderTraverse(root->right);
}

void preorderTraverse(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}

int main(void) {
    int numNodes;
    cin >> numNodes;
    vector<string> nodeValues(numNodes);
    for (int i = 0; i < numNodes; i++) cin >> nodeValues[i];
    TreeNode* root = buildTree(nodeValues);
    cout << "In-order Traversal: " << endl;
    inorderMorrisTraverse(root);
    cout << endl;
    inorderTraverse(root);
    cout << endl;
    cout << "Pre-order Traversal: " << endl;
    preorderMorrisTraverse(root);
    cout << endl;
    preorderTraverse(root);
    cout << endl;
}
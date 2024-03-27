#include <iostream>
#include <stack>
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
    vector<TreeNode*> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> ans;
        stack<pair<TreeNode*, bool>> myStack;
        myStack.push({root, false});
        while (!myStack.empty()) {
            TreeNode* currentNode = myStack.top().first;
            bool print = myStack.top().second;
            myStack.pop();
            if (!currentNode) continue;
            if (print) {
                ans.push_back(currentNode);
                continue;
            }
            myStack.push({currentNode->right, false});
            myStack.push({currentNode, true});
            myStack.push({currentNode->left, false});
        }
        return ans;
    }
    void swapNode(TreeNode *first, TreeNode *second) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder = inorderTraversal(root);
        int first, size = inorder.size();
        for (int i = 0; i < size - 1; i++) {
            if (inorder[i]->val > inorder[i+1]->val) {
                first = i;
                break;
            }
        }
        int second, min = INT32_MAX;
        for (int i = first+1; i < size; i++) {
            if (inorder[i]->val < min) {
                min = inorder[i]->val;
                second = i;
            }
        }
        swapNode(inorder[first], inorder[second]);
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
    sol.recoverTree(root);
    vector<TreeNode*> ans = sol.inorderTraversal(root);
    for (int i = 0; i < ans.size(); i++) cout << ans[i]->val << " ";
    cout << endl;
}
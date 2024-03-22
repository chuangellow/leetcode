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

class Solution {
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
    int findInorder(vector<int>& inorder, int target, const int size) {
        for (int i = 0; i <= size-1; i++) if (inorder[i] == target) return i;
        return -1;
    }
    TreeNode* recursiveBuild(int *pos, int left, int right, vector<int>& preorder, vector<int>& inorder, const int size) {
        cout << "pos: " << *pos << "left: " << left << "right: " << right << endl;
        if (*pos >= size) return nullptr;
        if (left > right) return nullptr;
        TreeNode* root = new TreeNode(preorder[*pos]);
        if (left == right) return root;
        int rootIdx = findInorder(inorder, preorder[*pos], size);
        *pos = *pos + 1;
        if (*pos < size && findInorder(inorder, preorder[*pos], size) < rootIdx) {
            root->left = recursiveBuild(pos, left, rootIdx-1, preorder, inorder, size);
            *pos = *pos + 1;
            root->right = recursiveBuild(pos, rootIdx+1, right, preorder, inorder, size);
            if (root->left == nullptr || root->right == nullptr) {
                *pos = *pos - 1;
            }
        }
        else {
            root->right = recursiveBuild(pos, rootIdx+1, right, preorder, inorder, size);
            if (root->right == nullptr) *pos = *pos - 1;
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        int pos = 0;
        return recursiveBuild(&pos, 0, size-1, preorder, inorder, size);
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
    vector<int> preorder(n);
    for (int i = 0; i < n; i++) cin >> preorder[i];
    vector<int> inorder(n);
    for (int i = 0; i < n; i++) cin >> inorder[i];
    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);
    sol.showTree(root);
    return 0;
}
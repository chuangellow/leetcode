#include <iostream>
#include <unordered_set>
#include <unordered_map>
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
    TreeNode* recursiveBuild(int *pos, int left, int right, vector<int>& preorder, unordered_map<int, int>& hashMap, int size) {
        if (*pos > size) return nullptr;
        if (left > right) return nullptr;
        int rootVal = preorder[*pos];
        *pos = *pos + 1;
        TreeNode* root = new TreeNode(rootVal);
        root->left = recursiveBuild(pos, left, hashMap[rootVal]-1, preorder, hashMap, size);
        root->right = recursiveBuild(pos, hashMap[rootVal]+1, right, preorder, hashMap, size);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        int pos = 0;
        unordered_map<int, int> hashMap;
        for (int i = 0; i < size; i++) {
            hashMap[inorder[i]] = i;
        }
        return recursiveBuild(&pos, 0, size-1, preorder, hashMap, size);
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
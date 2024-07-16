#include <iostream>
#include <vector>
#include <string>
#include <queue>

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
    TreeNode* getLCA(TreeNode* root, int startValue, int destValue) {
        if (root == nullptr || root->val == startValue || root->val == destValue) return root;
        TreeNode* left = getLCA(root->left, startValue, destValue);
        TreeNode* right = getLCA(root->right, startValue, destValue);
        if (left != nullptr && right != nullptr) return root;
        return (left != nullptr)? left: right;
    }
    int getLevel(TreeNode* node, int startValue) {
        if (node == nullptr) return -1;
        if (node->val == startValue) return 0;
        int left = getLevel(node->left, startValue);
        int right = getLevel(node->right, startValue);
        return (left == -1 && right == -1)? -1: max(left, right) + 1;
    }
    void goToDest(TreeNode* node, int destValue, string& temp, string& s) {
        if (node == nullptr) return;
        if (node->val == destValue) {
            s = s + temp;
            return;
        }
        temp.push_back('L');
        goToDest(node->left, destValue, temp, s);
        temp.pop_back();
        temp.push_back('R');
        goToDest(node->right, destValue, temp, s);
        temp.pop_back();
        return;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = getLCA(root, startValue, destValue);
        int level = getLevel(lca, startValue);
        string s;
        for (int i = 0; i < level; i++) s.push_back('U');
        string temp;
        goToDest(lca, destValue, temp, s);
        return s;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int startValue, destValue;
    cin >> startValue >> destValue;
    TreeNode* root = buildTree(nums);
    Solution sol;
    cout << sol.getDirections(root, startValue, destValue) << endl;
    return 0;
}
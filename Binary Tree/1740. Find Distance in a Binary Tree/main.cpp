#include <iostream>
#include <vector>
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
    int distance = -1;
    bool find = false;
    pair<int, int> dfs(int level, TreeNode* root, int p, int q) {
        if (root == nullptr) return {-1, -1};
        pair<int, int> left = dfs(level+1, root->left, p, q);
        pair<int, int> right = dfs(level+1, root->right, p, q);
        pair<int, int> result = {-1, -1};
        result.first = max(left.first, right.first);
        result.second = max(left.second, right.second);
        if (root->val == p) result.first = level;
        if (root->val == q) result.second = level;
        if ((left.first != -1 && right.second != -1) || (left.second != -1 && right.first != -1)) {
            distance = result.first + result.second - 2 * level;
            find = true;
        }
        else if (!find && result.first != -1 && result.second != -1) {
            distance = abs(result.first - result.second);
            find = true;
        }
        return result;
    }
    int findDistance(TreeNode* root, int p, int q) {
        pair<int, int> ret = dfs(0, root, p, q);
        return distance;
    }
};

int main(void) {
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    TreeNode* root = buildTree(nums);
    Solution sol;
    cout << sol.findDistance(root, p, q) << endl;
    return 0;
}
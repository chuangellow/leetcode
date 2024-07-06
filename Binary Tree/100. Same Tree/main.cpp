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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        else if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(void) {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> nums1(n1);
    for (int i = 0; i < n1; i++) cin >> nums1[i];
    TreeNode *root1 = buildTree(nums1);
    vector<int> nums2(n2);
    for (int i = 0; i < n2; i++) cin >> nums2[i];
    TreeNode *root2 = buildTree(nums2);
    Solution sol;
    cout << sol.isSameTree(root1, root2) << endl;
    return 0;
}
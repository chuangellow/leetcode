#include <iostream>
#include <vector>
#include <queue>
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
    int getMinimumDifference(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;
        s.push({root, 0});
        int prev = -1;
        int minDiff = INT32_MAX;
        while (!s.empty()) {
            TreeNode* currentNode = s.top().first;
            int time = s.top().second;
            s.pop();
            if (currentNode == nullptr) continue;
            if (time == 1) {
                if (prev != -1) minDiff = min(currentNode->val - prev, minDiff);
                prev = currentNode->val;
                continue;
            }
            s.push({currentNode->right, 0});
            s.push({currentNode, 1});
            s.push({currentNode->left, 0});
        }
        return minDiff;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution sol;
    return 0;
}
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
    bool dfs(TreeNode* node, int destValue, string& s) {
        if (node == nullptr) return false;
        if (node->val == destValue) {
            return true;
        }
        s.push_back('L');
        bool left = dfs(node->left, destValue, s);
        if (left) return true;
        s.pop_back();
        s.push_back('R');
        bool right = dfs(node->right, destValue, s);
        if (right) return true;
        s.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string result, toStartStr, toDestStr;
        dfs(root, startValue, toStartStr);
        dfs(root, destValue, toDestStr);
        int minLen = min(toStartStr.size(), toDestStr.size());
        int commonIdx = 0;
        while (commonIdx < minLen && toStartStr[commonIdx] == toDestStr[commonIdx]) {
            commonIdx++;
        }
        for (int i = commonIdx; i < toStartStr.size(); i++) {
            result.push_back('U');
        }
        for (int i = commonIdx; i < toDestStr.size(); i++) {
            result.push_back(toDestStr[i]);
        }
        return result;
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
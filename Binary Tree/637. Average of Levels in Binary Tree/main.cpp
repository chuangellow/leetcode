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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<double, int>> statistics;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            TreeNode *currentNode = q.front().first;
            int level = q.front().second;
            q.pop();
            if (currentNode == nullptr) continue;
            if (level > statistics.size()) {
                statistics.push_back({(double) currentNode->val, 1});
            }
            else {
                statistics[level-1].first = statistics[level-1].first + (double) currentNode->val;
                statistics[level-1].second++;
            }
            q.push({currentNode->left, level+1});
            q.push({currentNode->right, level+1});
        }
        int n = statistics.size();
        vector<double> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = statistics[i].first / statistics[i].second;
        }
        return result;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    TreeNode *root = buildTree(nums);
    Solution sol;
    vector<double> result = sol.averageOfLevels(root);
    for (auto r: result) {
        cout << r << " ";
    }
    return 0;
}
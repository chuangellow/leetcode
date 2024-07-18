#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

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
    vector<TreeNode*> leafs;
    unordered_map<TreeNode*, TreeNode*> parents;
    int count = 0;
    int numLeafs;
    void dfs(TreeNode* node, TreeNode* parent) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) {
            leafs.push_back(node);
            parents[node] = parent;
            return;
        }
        parents[node] = parent;
        dfs(node->left, node);
        dfs(node->right, node);
    }
    void bfs(int i, TreeNode* source, int distance) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> distances;
        distances[source] = 0;
        q.push(source);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (distances[current] > distance) break;
            if (current->left != nullptr && distances.count(current->left) == 0) {
                distances[current->left] = distances[current] + 1;
                q.push(current->left);
            }
            if (current->right != nullptr && distances.count(current->right) == 0) {
                distances[current->right] = distances[current] + 1;
                q.push(current->right);
            }
            if (parents[current] != nullptr && distances.count(parents[current]) == 0) {
                distances[parents[current]] = distances[current] + 1;
                q.push(parents[current]);
            }
        }
        for (int j = i + 1; j < numLeafs; j++) {
            if (distances.count(leafs[j]) == 0) continue;
            if (distances[leafs[j]] <= distance) count++;
        }
        return;
    }
    int countPairs(TreeNode* root, int distance) {
        if (!root) return 0;
        dfs(root, nullptr);
        numLeafs = leafs.size();
        for (int i = 0; i < numLeafs; i++) {
            bfs(i, leafs[i], distance);
        }
        return count;
    }
};

int main(void) {
    int n, distance;
    cin >> n >> distance;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    TreeNode* root = buildTree(nums);
    Solution sol;
    cout << sol.countPairs(root, distance) << endl;
    return 0;
}
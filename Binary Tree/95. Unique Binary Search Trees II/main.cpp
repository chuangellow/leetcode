#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <functional>
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

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ h2;  
    }
};

class Solution {
public:
    void inorderTraverse(TreeNode *root) {
        if (root == nullptr) return;
        inorderTraverse(root->left);
        cout << root->val << " ";
        inorderTraverse(root->right);
    }
    vector<TreeNode*> genTree(int left, int right, unordered_map<pair<int, int>, vector<TreeNode*>, pair_hash>& hashMap) {
        if (left > right) return {nullptr};
        vector<TreeNode*> roots;
        if (hashMap.find({left, right}) != hashMap.end()) {
            return hashMap[{left, right}];
        }
        for (int i = left; i <= right; i++) {
            vector<TreeNode*> leftRoots = genTree(left, i-1, hashMap);
            vector<TreeNode*> rightRoots = genTree(i+1, right, hashMap);
            for (TreeNode* leftRoot: leftRoots) {
                for (TreeNode* rightRoot: rightRoots) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    roots.push_back(root);
                }
            }
        }
        hashMap[{left, right}] = roots;
        return roots;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> roots;
        unordered_map<pair<int, int>, vector<TreeNode*>, pair_hash> hashMap;
        roots = genTree(1, n, hashMap);
        return roots;
    }
};

int main(void) {
    int n;
    cin >> n;
    Solution sol;
    vector<TreeNode*> ans;
    ans = sol.generateTrees(n);
    for (TreeNode* root: ans) {
        sol.inorderTraverse(root);
        cout << endl;
    }
}
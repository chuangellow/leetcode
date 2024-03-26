#include <iostream>
#include <vector>
#include <string>
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

TreeNode* buildTree(const vector<string>& nodeValues) {
    if (nodeValues.empty()) return nullptr;

    TreeNode* root = new TreeNode(stoi(nodeValues[0])); // Assuming the first value is always the root and is not null
    vector<TreeNode*> nodes{root};

    for (size_t i = 1; i < nodeValues.size(); ++i) {
        if (nodeValues[i] != "null") {
            TreeNode* node = new TreeNode(stoi(nodeValues[i]));
            if (i % 2 == 1) { // Odd index, left child
                nodes[(i - 1) / 2]->left = node;
            } else { // Even index, right child
                nodes[(i - 2) / 2]->right = node;
            }
            nodes.push_back(node);
        }
    }

    return root;
}

class Solution {
public:
    bool findK(TreeNode* root, int k) {
        if (k == 1) return (root != nullptr);
        vector<int> paths;
        while (k > 1) {
            paths.push_back(k);
            k /= 2;
        }
        TreeNode* currentNode = root;
        int currentIdx = 1;
        while (currentNode != nullptr && !paths.empty()) {
            int parentIdx = paths.back();
            paths.pop_back();
            if (currentIdx * 2 == parentIdx) {
                currentIdx *= 2;
                currentNode = currentNode->left;
            }
            else if ((currentIdx * 2 + 1) == parentIdx) {
                currentIdx = currentIdx * 2 + 1;
                currentNode = currentNode->right;
            }
        }
        return (currentNode != nullptr);
    }
    int maxNodes(TreeNode* root) {
        int depth = 0;
        TreeNode* currentNode = root;
        while (currentNode != nullptr) {
            depth++;
            currentNode = currentNode->left;
        }
        return (2 << depth) - 1;
    }
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int left = 1, right = maxNodes(root);
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            bool exist = findK(root, mid);
            if (!exist) right = mid - 1;
            else left = mid;
        }
        return left;
    }
};

int main(void) {
    int numNodes;
    cin >> numNodes;
    vector<string> nodeValues(numNodes);
    for (int i = 0; i < numNodes; i++) cin >> nodeValues[i];
    TreeNode* root = buildTree(nodeValues);
    Solution sol;
    cout << sol.countNodes(root) << endl;
}